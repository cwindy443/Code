#include <bits/stdc++.h>
#define int long long 

using namespace std;

int n, b, ans = INT_MAX;
int h[25];

void dfs(int idx, int sum){
  if(idx == n + 1){
    if(sum - b >= 0)
      ans = min(sum - b, ans);
    return;
  }
  dfs(idx + 1, sum + h[idx]);
  dfs(idx + 1, sum);
}

signed main(){
  cin >> n >> b;
  for(int i = 1; i <= n; i++) cin >> h[i];
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}
