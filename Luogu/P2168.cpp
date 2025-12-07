#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define ll long long

struct Node
{
  ll w;
  int h;

  bool operator>(const Node& other) const {
    if (w != other.w) {
        return w > other.w;
    }
    return h > other.h;
  }
};

std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
int n;
int k;

signed main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> k;
  for(int i = 0; i < n; i++){
    ll x;
    std::cin >> x;
    pq.push({x, 1});
  }

  if (n == 1) {
      std::cout << 0 << std::endl;
      std::cout << 0 << std::endl;
      return 0;
  }

  if (k == 1) {
      return 1;
  }

  while ((pq.size() - 1) % (k - 1) != 0) {
      pq.push({0, 0});
  }

  ll total_cost = 0;

  while (pq.size() > 1) {
    ll combined_w = 0;
    int max_h = 0;

    for (int i = 0; i < k; ++i) {
      Node node = pq.top();
      pq.pop();
      combined_w += node.w;
      if (node.h > max_h) {
        max_h = node.h;
      }
    }

    total_cost += combined_w;
    pq.push({combined_w, max_h + 1});
  }

  std::cout << total_cost << std::endl;
  std::cout << pq.top().h - 1 << std::endl;

  return 0;
}
