#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int sums[N];

int main(){
  int T;
  cin >> T;
  while(T--){
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 5, 0);
    for(int i = 1; i <= n; i++){
      cin >> a[i];
      sums[i] = sums[i - 1] + a[i];
    }
    while(m--){
      int l, r;
      cin >> l >> r;
      cout << sums[r] - sums[l - 1] + (2 * m) << endl;
    }
  }
  return 0;
}
