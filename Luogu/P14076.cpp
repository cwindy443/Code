#include <iostream>
#include <vector>
#include <utility>
#define int long long

const int N = 1e5 + 5;
int n, sum, maxx;
std::vector<std::pair<int, int>> mp[N];

void dfs(int idx, int pre, int dist) {
  for(auto i : mp[idx]) {
    if(i.first != pre) {
      dfs(i.first, idx, dist + i.second);
    }
    maxx = std::max(dist, maxx);
  }
}

signed main() {
  std::cin.tie(nullptr);
  std::cin.sync_with_stdio(false);  
  std::cout.sync_with_stdio(false);

  std::cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v, l;
    std::cin >> u >> v >> l;
    mp[u].push_back({v, l});
    mp[v].push_back({u, l});
    sum += 2 * l;
  }
  
  dfs(1, 0, 0);
  std::cout << sum - maxx << std::endl;

  return 0;
}