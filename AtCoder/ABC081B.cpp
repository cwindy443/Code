#include <bits/stdc++.h>

using namespace std;

const int N = 205;
int n;

int main(){
  cin >> n;
  int ans = INT_MAX;
  for(int i = 1; i <= n; i++) {
    int num, cnt = 0;
    cin >> num;
    if(num & 1){
      cout << 0 << endl;
      return 0;
    }
    while(!(num & 1)){
      num /= 2;
      cnt++;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
