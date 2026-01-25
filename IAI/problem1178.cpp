#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s, t;
  std::cin >> s >> t;

  size_t len = s.size();

  if (len != t.size()) {
    std::cout << "No" << std::endl;
    return 0;
  }

  int s_count[26] = {0};
  int t_count[26] = {0};
  for (size_t i = 0; i < len; i++) {
    s_count[s[i] - 'a']++;
    t_count[t[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (s_count[i] != t_count[i]) {
      std::cout << "No" << std::endl;
      return 0;
    }
  }

  if (s == t) {
    std::cout << "Yes" << std::endl;
    return 0;
  }

  for (size_t i = 0; i < len - 1; i++) {
    std::string temp = s;
    std::swap(temp[i], temp[i + 1]);

    if (temp == t) {
      std::cout << "Yes" << std::endl;
      return 0;
    }
  }

  std::cout << "No" << std::endl;
  return 0;
}
