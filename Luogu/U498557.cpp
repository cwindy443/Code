#include <iostream>
#include <ostream>

int y, m;
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::cin >> y >> m;
  if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
    std::cout << (m == 2 ? days[m] + 1 : days[m]) << std::endl;
  } else {
    std::cout << days[m] << std::endl;
  }
  return 0;
}
