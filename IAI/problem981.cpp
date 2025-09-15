#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
int ans = 1;
vector<int> a(N);

int main() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 2; i <= n; i++) {
    a[i] += a[i - 1];
  }
  int minn = 1e9;
  for (int i = 1; i <= n; i++) {
    minn = min(minn, a[i]);
  }

  if (minn >= 0)
    cout << ans << endl;
  else
    cout << ans - minn << endl;
  return 0;
}
