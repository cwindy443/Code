#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n;
int a[N];
int dp[N];

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }


  for(int i = 1; i <= n; i++){
    dp[i] = max(a[i], dp[i - 1] + a[i]);
  }

  int ans = INT_MIN;
  for(int i = 1; i <= n; i++)
    ans = max(ans, dp[i]);

  cout << ans << endl;
  return 0;
}
