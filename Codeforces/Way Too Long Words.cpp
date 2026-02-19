#include <iostream>
#include <string>
using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    if(str.size() > 10) {
      cout << str[0] << str.size() - 2 << str[str.size() - 1] << endl;
    }
    else {
      cout << str << endl;
    }
  }
  return 0;
}
