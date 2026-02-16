#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int d;
  string s;
  cin >> d >> s;

  int n = s.size();
  string ans;

  for (int i = 0; i < n; i++) {
    while (d > 0 && !ans.empty() && ans.back() < s[i]) {
      ans.pop_back();
      d--;
    }
    ans += s[i];
  }

  while (d > 0) {
    ans.pop_back();
    d--;
  }

  cout << ans << endl;
  return 0;
}
