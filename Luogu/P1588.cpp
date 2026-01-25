#include <iostream>
#include <queue>
#include <unordered_set>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    int x, y;
    std::cin >> x >> y;

    // BFS to find shortest path
    std::queue<std::pair<int, int>> q; // {position, steps}
    std::unordered_set<int> visited;

    q.push({x, 0});
    visited.insert(x);

    while (!q.empty()) {
      int pos = q.front().first;
      int steps = q.front().second;
      q.pop();

      if (pos == y) {
        std::cout << steps << std::endl;
        break;
      }

      // Try all three moves
      int next_positions[] = {pos + 1, pos - 1, pos * 2};

      for (int next_pos : next_positions) {
        // Prune: keep positions within reasonable bounds
        // Since y <= 10^5, we don't need to go beyond 2*y
        if (next_pos > 0 && next_pos <= 2 * y &&
            visited.find(next_pos) == visited.end()) {
          visited.insert(next_pos);
          q.push({next_pos, steps + 1});
        }
      }
    }
  }

  return 0;
}
