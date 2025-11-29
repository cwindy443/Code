#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int n, d;

int main(){
  std::cin.tie(NULL);
  std::cin.sync_with_stdio(false);

  std::cin >> n >> d;
  std::vector<std::vector<int>> mp(n + 5);
  for(int i = 1; i < n; i++){
    int u, v;
    std::cin >> u >> v;
    mp[u].push_back(v);
    mp[v].push_back(u);
  }
  
  std::vector<bool> vis(n + 5, false);
  std::queue<std::pair<int, int>> q;
  q.push({1, 0});
  vis[1] = true;

  int ans = 0;
  while(!q.empty()){
    int node = q.front().first, dis = q.front().second;
    q.pop();
    if(dis > d) continue;
    if(dis > 0) ans++;
    for(int neigh : mp[node]){
      if(!vis[neigh]){
        vis[neigh] = true;
        q.push({neigh, dis + 1});
      }
    }
  }
  std::cout << ans << std::endl;
}