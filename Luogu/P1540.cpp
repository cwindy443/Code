#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
int main() {
  cin >> m >> n;
  vector<int> v;
  while (n--) {
    int num;
    cin >> num;
    if (find(v.begin(), v.end(), num) == v.end()) {
      v.push_back(num);
      ans++;
    }
    if (v.size() > m)
      v.erase(v.begin());
  }
  cout << ans << endl;
  return 0;
}
