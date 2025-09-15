#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll multi(ll n){
  ll ans = 1;
  for(int i = 2; i <= n; i++)
    ans *= i;
  return ans;
}

ll double_multi(ll n){
  ll ans = 1;
  if(n & 1){
    for(ll i = n; i >= 1; i -= 2){
      ans *= i;
    }
  }
  else{
    for(ll i = n; i >= 2; i -= 2){
      ans *= i;
    }
  }
  return ans;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    ll n;
    cin >> n;
    cout << 2 * (multi(n) / double_multi(n)) << endl;
  }
  return 0;
}
