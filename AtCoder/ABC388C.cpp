#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 5;
int n;
int a[N];
int sum[N];

signed main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }

  long long ans = 0;
  int j = 1;
  for(int i = 1; i <= n; i++){
    while (j <= n && a[j] < 2 * a[i]) {
      j++;
    }
    if (j <= n) {
      ans += (n - j + 1);
    }
  }
  cout << ans << endl;
  return 0;
}
