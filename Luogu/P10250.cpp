#include <bits/stdc++.h>
#define LL long long

using namespace std;

int n;
LL dp[1005];

int main() {
  cin >> n;

  dp[0] = 1;
  dp[1] = 2;
  dp[2] = 4;
  for (int i = 3; i < n; i++) {
    dp[i] = max(dp[i], dp[i - 1] + dp[i - 2] + dp[i - 3]);
  }
  /*
   for (int i = 1; i <= n; i++) {
     cout << dp[i] << endl;
   }
   */

  cout << dp[n - 1] << endl;
  return 0;
}
