#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 3e5 + 5;
int n, q;
ll sum[N];

int main(){
  cin >> n >> q;
  string s;
  cin >> s;
  for(int i = 0; i < n; i++){
    if(s[i] == s[i + 1]) sum[i + 1] = sum[i] + 1;
    else sum[i + 1] = sum[i];
  }
  while(q--){
    int l, r;
    cin >> l >> r;
    cout << sum[r - 1] - sum[l - 1] << endl;
  }
  return 0;
}
