#include <iostream>
#include <vector>

// Using std namespace for competitive programming convenience
using namespace std;

const int MOD = 998244353;
const int MAX_N = 2005;
const int MAX_2N = 4005;

long long fact[MAX_2N];
long long invFact[MAX_2N];

// Modular exponentiation to calculate (base^exp) % MOD
long long power(long long base, long long exp) {
  long long res = 1;
  base %= MOD;
  while (exp > 0) {
    if (exp % 2 == 1)
      res = (res * base) % MOD;
    base = (base * base) % MOD;
    exp /= 2;
  }
  return res;
}

// Modular inverse using Fermat's Little Theorem
long long modInverse(long long n) { return power(n, MOD - 2); }

// Precompute factorials and their modular inverses
void precompute_factorials(int max_val) {
  fact[0] = 1;
  invFact[0] = 1;
  for (int i = 1; i <= max_val; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    invFact[i] = modInverse(fact[i]);
  }
}

// Calculate combinations C(n, k) % MOD
long long combinations(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  return (((fact[n] * invFact[k]) % MOD) * invFact[n - k]) % MOD;
}

int main() {
  // Fast I/O
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  // R[i] stores the number of red crystals for magician i
  vector<int> R(n + 1);
  for (int i = 1; i <= n; i++) {
    int type;
    cin >> type;
    if (type == 0)
      R[i] = 2; // 2 red
    else if (type == 1)
      R[i] = 1; // 1 red
    else
      R[i] = 0; // 0 red
  }

  precompute_factorials(2 * n);

  // dp[i][j]: number of distinct sequences from magician i with j red crystals
  vector<vector<long long>> dp(n + 2, vector<long long>(2 * n + 1, 0));

  // Base case: magician n
  // The sequence from magician n has length 2 and R[n] red crystals.
  dp[n][R[n]] = combinations(2, R[n]);

  // DP transition: iterate from magician n-1 down to 1
  for (int i = n - 1; i >= 1; i--) {
    int L_i = 2 * (n - i + 1);
    int L_i_plus_1 = 2 * (n - (i + 1) + 1);

    for (int j = 0; j <= L_i; j++) {
      // Number of red crystals needed from magician i+1
      int k = j - R[i];

      // Check if k is a possible number of red crystals from i+1's sequence
      if (k >= 0 && k <= L_i_plus_1) {
        if (dp[i + 1][k] > 0) {
          long long comb = combinations(L_i, j);
          dp[i][j] = (dp[i + 1][k] * comb) % MOD;
        }
      }
    }
  }

  // Final answer is the sum of all possible sequences from magician 1
  long long total_sequences = 0;
  for (int j = 0; j <= 2 * n; j++) {
    total_sequences = (total_sequences + dp[1][j]) % MOD;
  }

  cout << total_sequences << endl;

  return 0;
}
