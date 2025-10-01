#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;
int n;
int a[N];
unordered_map<int, int> mp;

signed main(){
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  int ans = 0;
  for(int j = 1; j <= n; j++){
    int cnt = j - a[j];
    if(mp.find(cnt) != mp.end()){
      ans += mp[cnt];
    }
    mp[j + a[j]]++;
  }
  cout << ans << endl;
  return 0;
}
