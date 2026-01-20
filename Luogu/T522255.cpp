#include <algorithm>
#include <iostream>

int minn(int a, int b, int c, int d) {
  return std::min(a, std::min(b, std::min(c, d)));
}

int maxx(int a, int b, int c, int d) {
  return std::max(a, std::max(b, std::max(c, d)));
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int max_min = minn(a, b, c, d), max_max = maxx(a, b, c, d);
    if (max_min + max_max == (a + b + c + d - max_min - max_max)) {
      std::cout << "Yes" << std::endl;
    } else
      std::cout << "No" << std::endl;
  }

  return 0;
}
