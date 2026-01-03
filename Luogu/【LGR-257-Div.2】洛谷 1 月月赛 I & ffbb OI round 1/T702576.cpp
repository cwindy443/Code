#include <iostream>
#include <string>

int T;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> T;
  while(T--) {
    int n, a, b, c;
    std::string s;
    std::cin >> n >> a >> b >> c;
    std::cin >> s;
    int ans = 0;
    for(int i = 0 ; i < n; ) {
      if(s[i] == '5') {
        if(s[i + 1] == '2') { 
          if(s[i + 2] == '0') {
            ans++;
            i += 2;
          }
        }
        else if(s[i + 1] == '0') {
          b--;
          ans++;
          i++;
        }
        else {
          i++;
        }
      }
      else if(s[i] == '2') {
        if(i == 0) {
          if(s[i + 1] == '0') {
            a--;
            ans++;
            i++;
          }
        }
        else {
          if(s[i - 1] == '5') {
            if(s[i + 1] == '0') {
              ans++;
              i++;
            }
          }
          i++;  
        }
      }
      else if(s[i] == '0') {
        if(i == 0) continue;
        else {
          if(i > 1 && s[i - 2] == '5' && s[i - 1] == '2') {
            ans++;
            i += 2;
          }
          if(i > 0 && s[i - 1] == '2') {
            a--;
            ans++;
            i++;
          }
        }
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}