#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[105][105], f[105][105], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool vis[105][105];

int dfs(int x, int y) {
  if (f[x][y])
    return f[x][y];             // 返回已知
  for (int i = 0; i < 4; i++) { // 四个方向
    int nx = x + dx[i], ny = y + dy[i];
    if (nx > n || nx < 1 || ny > m || ny < 1)
      continue;                // 判断边界
    if (a[nx][ny] < a[x][y]) { // 能否
      f[x][y] = max(dfs(nx, ny) + 1, f[x][y]);
    }
  }
  if (f[x][y])
    return f[x][y]; // 返回跟更新完的值
  return 1;         // 如果f[x][y]没有更新，代表周围都比高
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  int ans = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans = max(ans, dfs(i, j));
    }
  }
  cout << ans << endl;
  return 0;
}
