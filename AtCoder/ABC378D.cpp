#include <bits/stdc++.h>

using namespace std;

int h, w, k, ans;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
char mp[15][15];
bool vis[15][15];

void dfs(int x, int y, int cnt){
  if(vis[x][y] || mp[x][y] == '#'){
    return;
  }

  if(cnt == k){
    ans++;
    return;
  }

  vis[x][y] = true;

  for(int i = 0; i < 4; i++){
    int nx = dx[i] + x, ny = dy[i] + y;
    if(nx >= 1 && nx <= h && ny >= 1 && ny <= w){
      dfs(nx, ny, cnt + 1);
    }
  }

  vis[x][y] = false;
}

int main(){
  cin >> h >> w >> k;
  for(int i = 1; i <= h; i++){
    for(int j = 1; j <= w; j++){
      cin >> mp[i][j];
    }
  }
  for(int i = 1; i <= h; i++){
    for(int j = 1; j <= w; j++){
      memset(vis, 0, sizeof(vis));
      dfs(i, j, 0);
    }
  }
  cout << ans << endl;
  return 0;
}
