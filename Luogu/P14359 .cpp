#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a, sums;
vector<int> pre;

int main(){
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    int num; cin >> num;
    a.push_back(num);
  }

  for(int i = 1; i <= n; i++){
    int f;
    sums[i] ^= sums[i - 1];
    f = sums[i] ^ k;
    lower_bound()
  }
  
  return 0;
} 