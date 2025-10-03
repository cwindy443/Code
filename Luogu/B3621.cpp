#include <iostream>

using namespace std;

int n, k;
int vis[10];

void dfs(int cnt){
  if(cnt == n + 1){
    for (int i = 1; i <= n; i++)
      cout << vis[i] << " ";
    cout << endl;
    return;
  }
  for (int i = 1; i <= k; i++) {
    vis[cnt] = i;
    dfs(cnt + 1);
  }
}

int main(){
  cin >> n >> k;
  dfs(1);
  return 0;
}
