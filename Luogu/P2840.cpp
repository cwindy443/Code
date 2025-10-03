#include <bits/stdc++.h>

using namespace std;

int n, w;
int a[1005], dp[10005];
const int MOD = 1e9 + 7;

int main(){
  cin >> n >> w;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  dp[0] = 1;
  for(int i = 1; i <= w; i++){
    for(int j = 1; j <= n; j++){
      if(i - a[j] >= 0){
        dp[i] = (dp[i] + dp[i - a[j]]);
        dp[i] %= MOD;
      }
    }
  }
  cout << dp[w] % MOD << endl;
  return 0;
}
