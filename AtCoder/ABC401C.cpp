#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 5, MOD = 1e9;
int n, k;
int a[N];

signed main(){
  cin >> n >> k;

  if (n < k) {
    cout << 1 << endl;
    return 0;
  }

  for (int i = 0; i < k; ++i) {
    a[i] = 1;
  }

  a[k] = k;

  for (int i = k + 1; i <= n; ++i) {
    a[i] = (2 * a[i - 1] - a[i - k - 1]) % MOD;
    if (a[i] < 0) {
      a[i] += MOD;
    }
  }

  cout << a[n] % MOD << endl;

  return 0;
}
