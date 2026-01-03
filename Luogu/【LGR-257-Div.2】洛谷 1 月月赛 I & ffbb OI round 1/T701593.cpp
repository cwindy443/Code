#include <iostream>

int T;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> T;
  while(T--) {
    int n;
    std::cin >> n;
    std::cout << n - 1 << " " << n / 2 << std::endl;
  }
  return 0;
}