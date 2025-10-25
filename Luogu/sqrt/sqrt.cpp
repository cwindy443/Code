#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

int q;

int main(){
  cin >> q;
  while(q--){
    int n;
    ll ans = 0;
    cin >> n;
    ans = ((int)sqrt(n) - 1) * 3 + 1;
    ans += (n - (int)pow((int)sqrt(n), 2)) / ans;
    cout << ans << endl;
  }
  return 0;
}
