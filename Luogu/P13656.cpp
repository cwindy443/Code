#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 5;
int n;
int a[N];
int sum[N];

signed main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    int s = 0;
    bool found = false;
    for(int j = i; j <= n; j++){
      s += a[j];
      if(s % 10 == 0){
        cout << j - i + 1 << " ";
        found = true;
        break;
      }
    }
    if(!found) cout << -1 << " ";
  }
  return 0;
}
