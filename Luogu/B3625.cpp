#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
char mp[105][105];
bool vis[105][105];

void dfs(int x, int y){
  if(mp[x][y] == '#' || vis[x][y]) return;

  vis[x][y] = true;

  if(x == n && y == m){
    cout << "Yes" << endl;
    exit(0);
  }

  for(int i = 0; i < 4; i++){
    int nx = dx[i] + x, ny = dy[i] + y;
    if(nx >= 1 && nx <= n && ny >= 1 && ny <= m){
      dfs(nx, ny);
    }
  }

}

int main(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> mp[i][j];
    }
  }
  dfs(1, 1);
  cout << "No" << endl;
  return 0;
}
