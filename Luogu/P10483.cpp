#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int n, w, ans = 20;
int c[25], sum[25];

void dfs(int u, int k) {
  if (k >= ans)
    return;
  if (u >= n + 1) {
    ans = k;
    return;
  }
  for (int i = 1; i <= k; i++) {
    if (sum[i] + c[u] <= w) {
      sum[i] += c[u];
      dfs(u + 1, k);
      sum[i] -= c[u];
    }
  }
  sum[k + 1] = c[u];
  dfs(u + 1, k + 1);
  sum[k + 1] = 0;
}

int main() {
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  sort(c + 1, c + 1 + n, greater<int>());
  dfs(1, 1);
  cout << ans << endl;
  return 0;
}
