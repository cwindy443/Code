#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> q;
  while(q--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s == t) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  
  return 0;
}
