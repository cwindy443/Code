#include <iostream>
#include <algorithm>
#include <vector>

const int N = 1e3 + 5;
int n, m;
int mp[N][N];
std::vector<int> lists[N];

int main(){
  std::cin >> n >> m;
  for(int i = 1; i <= m; i++){
    int u, v;
    std::cin >> u >> v;
    mp[u][v] = 1;
    mp[v][u] = 1;
    lists[u].push_back(v);
    lists[v].push_back(u);
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      std::cout << mp[i][j] << " ";
    }
    std::cout << std::endl;
  }
  //std::cout << std::endl;
  for(int i = 1; i <= n; i++){
    std::cout << lists[i].size() << " ";
    std::sort(lists[i].begin(), lists[i].end());
    for(auto val : lists[i]) std::cout << val << " ";
    std::cout << std::endl;
  }
  return 0;
}