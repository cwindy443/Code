#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
int n;
int v[N], f[N][N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int len = n - 1; len >= 1; len--) {
    for (int i = 1; i < n; i++) {
      int j = len + i - 1;
      if (j > n)
        break;
      if (i - 1 >= 1)
        f[i][j] = max(f[i][j], f[i - 1][j] + v[i - 1] * (n - len));
      if (j + 1 >= 1)
        f[i][j] = max(f[i][j], f[i][j + 1] + v[j + 1] * (n - len));
    }
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, f[i][i] + v[i] * n);
  }
  cout << ans << endl;
  return 0;
}
