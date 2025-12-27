#include <iostream>
#include <cmath>

int s[4];

int main() {
  std::cin >> s[1] >> s[2] >> s[3];
  if(s[1] >= 30 && s[1] <= 70) std::cout << s[1] << std::endl;  
  else if((s[2] >= 30 && s[2] <= 70) || (s[3] >= 30 && s[3] <= 70)) std::cout << std::min(s[2], s[3]) << std::endl;
  else std::cout << 0 << std::endl;
  return 0;
}