#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int num;
    cin >> num;
    a.push_back(num);
  }
  int sum = 0, ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    sum += a[i];
    ans = max(ans, sum - ans);
  }
  cout << ans << endl;
  return 0;
}
