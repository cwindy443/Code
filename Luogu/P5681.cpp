#include <iostream>

int a, b, c;

int main(){
  std::cin >> a >> b >> c;
  if( (long long) a * a > (long long) b * c) std::cout << "Alice" << std::endl;
  else std::cout << "Bob" << std::endl;
  return 0;
}