#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5;
int n, m;
char a[N][N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  return 0;
}
