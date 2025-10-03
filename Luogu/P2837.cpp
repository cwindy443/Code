#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5;
int n;
int a[N];
int dp[N];

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++){
    if(a[i] != a[i + 1]) dp[i + 1] = dp[i] + 1;
    else dp[i + 1] = dp[i];
  }
  cout << dp[n - 1] << endl;
  return 0;
}
