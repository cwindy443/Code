#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  sort(b.begin(), b.end());

  long long min_diff = 2000000007LL;

  for (int val_a : a) {
    auto it = lower_bound(b.begin(), b.end(), val_a);

    if (it != b.end()) {
      min_diff = min(min_diff, abs(static_cast<long long>(val_a) - *it));
    }

    if (it != b.begin()) {
      min_diff = min(min_diff, abs(static_cast<long long>(val_a) - *prev(it)));
    }
  }

  cout << min_diff << endl;

  return 0;
}
