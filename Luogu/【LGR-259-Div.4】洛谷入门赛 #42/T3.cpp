#include <iostream>

const int N = 1e5 + 5;
struct Potato {
  int x, p;
}potato[N];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++) {
    std::cin >> potato[i].x >> potato[i].p;
  }
  int ans_cnt = 0, ans_price = 0;
  for(int i = 1; i <= n; i++) {
    if(potato[i].p < 500 && potato[i].x >= 500) {
      ans_cnt++, ans_price += potato[i].p;
    }
  }
  std::cout << ans_cnt << " " << ans_price << std::endl;
  return 0;
}