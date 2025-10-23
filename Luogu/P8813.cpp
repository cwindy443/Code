#include <iostream>
#include <cmath>

int a, b;

int main(){
  std::cin >> a >> b;
  unsigned long long ans = std::pow(a, b);
  std::cout << ans << std::endl;
  return 0;
}