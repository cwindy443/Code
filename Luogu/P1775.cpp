#include <bits/stdc++.h>

using namespace std;

const int N = 1e3;
int n, a[N], sum[N];
int f[N][N];

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }

  for(int i = 1; i <= n; i++){
    sum[i] = sum[i - 1] + a[i];
  }

  for(int len = 2; len <= n; len++){
    for(int i = 1; i <= n; i++){
      int j = i + len - 1;
      if(j > n) break;
      f[i][j] = 1e9;
      for(int k = i; k < j; k++){
        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
      }
    }
  }
  cout << f[1][n] << endl;
  return 0;
}
