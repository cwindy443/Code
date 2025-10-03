#include <bits/stdc++.h>

using namespace std;

int h, w, ans;
char mp[1005][1005];
bool vis[1005][1005];
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

void bfs(int tx, int ty){
  queue<pair<int, int>> q;
  q.push({tx, ty});
  vis[tx][ty] = true;

  while(!q.empty()){
    auto cur_pair = q.front();
    q.pop();
    int x = cur_pair.first;
    int y = cur_pair.second;
    for(int i = 0; i < 8; i++){
      int nx = x + dx[i], ny = y + dy[i];
      if(nx < 1 || nx > h || ny < 1 || ny > w || vis[nx][ny] || mp[nx][ny] == '.') continue;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
}
int main(){
  cin >> h >> w;
  for(int i = 1; i <= h; i++){
    for(int j = 1; j <= w; j++){
      cin >> mp[i][j];
      vis[i][j] = false;
    }
  }

  for(int i = 1; i <= h; i++){
    for(int j = 1; j <= w; j++){
      if(!vis[i][j] && mp[i][j] == '#'){
        ans++;
        bfs(i, j);
      }
    }
  }

  cout << ans << endl;
  return 0;
}
