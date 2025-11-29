#include <iostream>
#include <queue>
#include <utility>

#define ll long long

struct Node
{
  ll v;
  ll dep;
  bool operator<(const Node &y) const{
    return v > y.v;
  }
};

std::priority_queue<Node> q;
int n, k;

signed main(){
  std::cin.tie(nullptr);
  std::cin.sync_with_stdio(false);

  std::cin >> n >> k;
  for(int i = 1; i <= n; i++){
    ll x;
    std::cin >> x;
    q.push({x, 0});
  }
  while((q.size() - 1) % (k - 1) != 0) q.push({0, 0});

  ll ans = 0;
  while(!(q.size() == 1)){
    for(int i = 1; i <= k; i++){
      ll x, y;
      x = q.top().v; q.pop();
      y = q.top().v; q.pop();
      q.push({x + y, i});
    }
  }

  std::cout << q.top().v << std::endl;

  return 0;
}