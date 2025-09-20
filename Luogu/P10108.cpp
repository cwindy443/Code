#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;
int n, m;
int a[105], b[N];
int dp[N];

int main()
{
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < n + n; i++)
  {
    dp[i] = -1e9;
  }
  dp[0] = 0;
  for (int i = 0; i < n + n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i >= a[j])
        dp[i] = max(dp[i], dp[i - a[j]] + b[i - a[j]]);
    }
  }
  int ans = -1e9;
  for(int i = n; i < n + n; i++){
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
