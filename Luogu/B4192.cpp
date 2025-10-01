#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 5;
int c[N];
ll sum[N];
int m, x, y;

int main(){
  cin >> m;
  for(int i = 1; i <= m; i++){
    cin >> c[i];
    sum[i] = sum[i - 1] + c[i];
  }
  cin >> x >> y;
  int ans = 0;
  for(int i = 1; i <= m; i++){
    if(sum[m] - sum[i] >= x && sum[m] - sum[i] <= y){
      if(sum[i] >= x && sum[i] <= y){
        ans = i + 1;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
