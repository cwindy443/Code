#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int n, target, leng;
int a[100], jump[100];
bool vis[100];

bool dfs(int x, int sum, int cnt) {
  if (cnt * target == leng)
    return 1;
  if (sum == target)
    return dfs();
}

int main() {
  int maxn = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    leng += a[i];
  }
  sort(a + 1, a + 1 + n, greater<int>());
  jump[n] = n;
  for (int i = n - 1; i >= 1; i--) {
    jump[i]
  }
  target = a[1];
  target = maxn;
  while (target <= leng) {
    if (leng % target == 0) {
      if (dfs(1, 0, 0)) {
        cout << target << endl;
        return 0;
      }
    }
    ++target;
  }
  return 0;
}
