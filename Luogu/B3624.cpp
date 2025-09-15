#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int n, l, r, ans;
int w[50];

void dfs(int sum, int x, int kind) {
  if (x <= 0)
    return;
  if (sum > r)
    return;
  if (sum + w[x] <= r && sum + w[x] >= l)
    ans++;
  dfs(sum + w[x], x - 1, kind - w[x]);
  dfs(sum, x - 1, kind - w[x]);
}

int main() {
  cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  sort(w + 1, w + 1 + n);
  dfs(0, n, accumulate(w + 1, w + 1 + n, 0));
  cout << ans << endl;
  return 0;
}
