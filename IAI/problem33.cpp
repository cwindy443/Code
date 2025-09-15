#include <cmath>
#include <iostream>

using namespace std;
// 前缀和 + abs

int main() {
  // Fast I/O
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  long long prefix_sum = 0;
  long long total_work = 0;
  long long current_val;

  for (int i = 0; i < n - 1; ++i) {
    cin >> current_val;
    prefix_sum += current_val;
    total_work += std::abs(prefix_sum);
  }

  cout << total_work << std::endl;

  return 0;
}
