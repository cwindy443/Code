#include <bits/stdc++.h>
#include <set>

using namespace std;

int x, y, p, ans;
set<pair<int, int>> f;

int dfs(int x, int y, int round) {
  auto it = f.insert({x, y});
  if (it.second == false)
    return 3;
  if (x == 0)
    return 1;
  else if (y == 0)
    return 2;
  if (round == 1) {
    return dfs((x + y) % p, y, round ^ 1);
  } else {
    return dfs(x, (x + y) % p, round ^ 1);
  }
}

int main() {
  int T;
  cin >> T >> p;
  while (T--) {
    f.clear();
    cin >> x >> y;
    int ans = dfs(x, y, 1);
    if (ans == 3)
      cout << "error" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
