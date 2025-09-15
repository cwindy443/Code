#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int n;
int a[N], sum[N];
int f[N][N], g[N][N];

int main(){
  cin >> n;

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    a[i + n] = a[i];
  }

  for(int i = 1; i <= 2 * n; i++){
    sum[i] = sum[i - 1] + a[i];
  }

  for(int len = 2; len <= n; len++){
    for(int i = 1; i <= 2 * n; i++){
      int j = i + len - 1;
      if(j > 2 * n) break;
      f[i][j] = 1e9, g[i][j] = -1;
      for(int k = i; k < j; k++){
        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
        g[i][j] = max(g[i][j], g[i][k] + g[k + 1][j] + sum[j] - sum[i - 1]);
      }
    }
  }

  int maxans = -1, minans = 1e9;
  for(int i = 1; i <= n; i++){
    minans = min(minans, f[i][n + i - 1]);
    maxans = max(maxans, g[i][n + i - 1]);
  }
  cout << minans << endl << maxans << endl;
  return 0;
}
