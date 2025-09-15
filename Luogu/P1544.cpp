#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k;
bool v[105][105][5055];
int a[105][105], f[105][105][5055];

int dfs(int x, int y, int cnt) {
  if (x < 0 || x > n || y < 0 || y > n)
    return 0;
  if (v[x][y][cnt])
    return f[x][y][cnt];
  if (cnt <= k) {
    f[x][y][cnt] = max(f[x][y][cnt], dfs(x + 1, y, cnt + 1) + a[x][y] * 3);
    f[x][y][cnt] = max(f[x][y][cnt], dfs(x + 1, y + 1, cnt + 1) + a[x][y] * 3);
  }
  v[x][y][cnt] = 1;
  f[x][y][cnt] = max(f[x][y][cnt], dfs(x + 1, y, cnt) + a[x][y]);
  f[x][y][cnt] = max(f[x][y][cnt], dfs(x + 1, y + 1, cnt) + a[x][y]);
  return f[x][y][cnt];
}

signed main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      cin >> a[i][j];

  memset(f, -0x3f, sizeof(f));
  int ans = dfs(1, 1, 0);
  cout << ans << endl;
  return 0;
}
