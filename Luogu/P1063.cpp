#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int n;
int a[N], f[N][N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }

  for (int len = 3; len <= n + 1; len++) {
    for (int i = 1; len + i - 1 <= 2 * n; i++) {
      int j = len + i - 1;
      f[i][j] = 1;
      for (int k = i + 1; k < j; k++) {
        f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
      }
    }
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, f[i][i + n]);
  }
  cout << ans << endl;
  return 0;
}
