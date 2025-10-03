#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int h, w, d;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int dist[N][N];
char mp[N][N];

void bfs(queue<pair<int, int>>& q){
  while(!q.empty()){
    auto cur_pair = q.front();
    q.pop();

    int cur_dist = dist[cur_pair.first][cur_pair.second];

    if(cur_dist == d) continue;

    for (int i = 0; i < 4; i++) {
      int nx = cur_pair.first + dx[i], ny = cur_pair.second + dy[i];
      if(nx < 1 || nx > h || ny < 1 || ny > w || dist[nx][ny] != -1 || mp[nx][ny] == '#') continue;
      dist[nx][ny] = cur_dist + 1;
      q.push({nx, ny});
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> h >> w >> d;

  queue<pair<int, int>> q;

  for(int i = 1; i <= h; i++){
    for(int j = 1; j <= w; j++){
      cin >> mp[i][j];
      dist[i][j] = -1;
      if(mp[i][j] == 'H'){
        dist[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  bfs(q);

  int ans = 0;
  for(int i = 1; i <= h; i++){
    for(int j = 1; j <= w; j++){
      if(dist[i][j] != -1){
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
