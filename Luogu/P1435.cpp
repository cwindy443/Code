#include <bits/stdc++.h>

using namespace std;

string s, pre;
int dp[1005][1005], len;

int main() {
  cin >> s;
  pre = s;

  reverse(s.begin(), s.end());
  s = '@' + s, pre = '@' + pre;
  len = s.size();

  for(int i = 1; i <= len; i++) {
    for(int j = 1; j <= len; j++){
      if(s[i] == pre[j])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  cout << len - dp[len][len] << endl;
  return 0;
}
