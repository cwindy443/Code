#include <algorithm>
#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>

const int N = 1e5 + 5;
int n, m;
std::vector<std::vector<int>> a(N);
bool vis[N];

void dfs(int idx) {
  vis[idx] = true;
  std::cout << idx << " ";
  for (auto i : a[idx]) {
    if (!vis[i]) {
      dfs(i);
    }
  }
}

void bfs(int idx) {
  std::queue<int> q;
  q.push(idx);
  vis[idx] = true;
  while (!q.empty()) {
    int val = q.front();
    std::cout << val << " ";
    q.pop();
    for (auto i : a[val]) {
      if (!vis[i]) {
        vis[i] = true;
        q.push(i);
      }
    }
  }
}

int main() {
  std::cin.tie(nullptr);
  std::cin.sync_with_stdio(false);

  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    a[x].push_back(y);
  }

  // Sort all adjacency lists once before traversal.
  for (int i = 1; i <= n; i++) {
    std::sort(a[i].begin(), a[i].end());
  }

  dfs(1);
  std::cout << std::endl;

  // Reset visited array for BFS.
  memset(vis, 0, sizeof(vis));

  bfs(1);
  return 0;
}
