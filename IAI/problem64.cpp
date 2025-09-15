#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 5;
int n, m;
int sum;
int p[N], c[N];

signed main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> p[i] >> c[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    sum += p[i];
    if (i >= m)
      sum -= p[i - m - 1];
    ans += sum >= c[i] ? c[i] : sum;
  }
  cout << ans << endl;
  return 0;
}
