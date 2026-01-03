#include <iostream>
#include <string>

int q;
int bucket[30];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::cin >> q;
  while(q--) {
    int n;
    bool flag = true;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    for(int i = 0; i < s.length(); i++) {
      bucket[s[i] - 'a']++;
    }
    for(int i = 0; i < t.length(); i++) {
      if(bucket[t[i] - 'a']) bucket[t[i] - 'a']--;
      else {
        std::cout << "NO" << std::endl;
        flag = false;
      }
    }
    for(int i = 0; i <= 26; i++) {
      if(bucket[i] != 0) {
        std::cout << "NO" << std::endl;
        flag = false;
      }
    }
    if(flag) std::cout << "YES" << std::endl;
  }
  return 0;
}