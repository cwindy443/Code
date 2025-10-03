#include <bits/stdc++.h>

using namespace std;

int n, m, cnt = 1;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int mark[1005][1005];
int ans[1000005];
int mp[1005][1005];

void bfs(int x, int y){
  queue<pair<int, int>> q;
  mark[x][y] = cnt;
  q.push({x, y});
  int p = 1;
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    for(int i = 0; i < 4; i++){
      int nx = t.first + dx[i], ny = t.second + dy[i];
      if(nx < 1 || nx > n || ny < 1 || ny > n || mp[t.first][t.second] == mp[nx][ny] || mark[nx][ny]) continue;
      mark[nx][ny] = cnt;
      q.push({nx, ny});
      p++;
    }
  }
  ans[cnt] = p;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      char ch;
      cin >> ch;
      mp[i][j] = ch - '0';
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(mark[i][j] == 0){
        bfs(i, j);
        cnt++;
      }
    }
  }

  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    cout << ans[mark[x][y]] << "\n";
  }

  return 0;
}
