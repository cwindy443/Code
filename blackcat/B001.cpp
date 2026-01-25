#include <iostream>
#include <vector>

int n, x;
std::vector<int> a;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int num;
    std::cin >> num;
    a.push_back(num);
  }
  std::cin >> x;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] + a[j] == x) {
        ans++;
      }
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
