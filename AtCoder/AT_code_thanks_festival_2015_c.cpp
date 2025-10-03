#include <bits/stdc++.h>

using namespace std;

int n, x;
int a[55];

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  cin >> x;
  int l = 1, r = n;
  while(l <= r){
    int mid = (l + r) >> 1;
    if(a[mid] < x) l = mid + 1;
    else r = mid - 1;
  }
  cout << l << endl;
  return 0;
}
