#include <iostream>

using namespace std;

int n, k, a[15];
bool vis[15];

void dfs(int cnt){
  if(cnt == k + 1){
    for(int i = 1; i <= k; i++){
      cout << a[i] << " ";
    }
    cout << endl;
    return;
  }
  for(int i = 1; i <= n; i++){
    if(vis[i]) continue;
    vis[i] = 1;
    a[cnt] = i;
    dfs(cnt + 1);
    vis[i] = 0;
  }
}

int main(){
  cin >> n >> k;
  dfs(1);
  return 0;
}
