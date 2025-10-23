#include <bits/stdc++.h>

using namespace std;

int n, m, k, Q;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
vector<vector<char>> mp;
vector<vector<int>> vis;

int main()
{
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);

  cin >> n >> m >> k >> Q;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> mp[i][j];
    }
  }
  for (int i = 1; i <= k; i++)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vis[x1][y1];
    vis[x2][y2];
  }
  queue<pair<int, int>> q;
  for (int i = 1; i <= Q; i++)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    q.push({x1, y1});
  }

  while(!q.empty()){
    auto np = q.front();
    q.pop();
    for(int i = 0; i < 4; i++){
      int nx = np.first + dx[i], ny = np.second + dy[i];
      
    }
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}