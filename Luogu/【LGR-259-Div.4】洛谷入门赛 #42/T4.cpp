#include <iostream>

int T;

int solve(int a, int b, int c) {
  int y = 1, res = 0;
  while(b * y < c) {
    int d = c - b * y;
    if(a % d == 0) {
      res++;
    }
    y++;
  }
  return res;
}

int main() {
  std::cin >> T;
  while(T--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << solve(a, b, c) << std::endl;
  }
  return 0;
}