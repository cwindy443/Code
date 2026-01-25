#include <algorithm>
#include <iostream>
#include <ostream>

const int N = 10005;
int n;
int a[N], b[N];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }

  std::sort(a + 1, a + 1 + n);
  std::sort(b + 1, b + 1 + n);

  int a_max = a[n], a_min = a[1], b_max = b[n], b_min = b[1];
  if (a_max < 0) {
    if (b_min < 0) {
      std::cout << a_min * b_min << std::endl;
    } else {
      std::cout << a_max * b_min << std::endl;
    }
  } else if (a_min > 0) {
    if (b_max > 0) {
      std::cout << a_max * b_max << std::endl;
    } else if (b_max < 0) {
      std::cout << a_min * b_max << std::endl;
    }
  } else
    std::cout << 0 << std::endl;
  return 0;
}
