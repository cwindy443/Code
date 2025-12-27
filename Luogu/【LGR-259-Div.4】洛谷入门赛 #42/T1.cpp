#include <iostream>
#include <cmath>

int s, b;

int main() {
  std::cin >> s >> b;
  std::cout << std::min(s / 3, b / 2) << std::endl;
  return 0;
}