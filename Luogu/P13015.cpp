#include <bits/stdc++.h>

using namespace std;

int n;
int a[4055], f[4055];

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    for(int j = i; j <= n; j++){
      f[j] = max(f[j], f[j - i] + a[i]);
    }
  }
  cout << f[n] << endl;
  return 0;
}
