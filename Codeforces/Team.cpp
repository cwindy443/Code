#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    vector<int> a;
    for(int i = 0; i < 3; i++) {
      int num;
      cin >> num;
      a.push_back(num);
    }
    int cnt = 0;
    for(auto i : a) {
      if(i == 1) cnt++;
    }
    if(cnt >= 2) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
