#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

std::vector<int> sums(100);
int n;

int main(){
  cin.tie(0);
  cin.sync_with_stdio(NULL);

  int cnt = 1;
  cin >> n;
  for(int i = 1; i <= n; i++){
    int num; cin >> num;
    sums[cnt] += num;
    if(i == pow(2, cnt) - 1){
      cnt++;
    }
  }
  int cmp = INT_MIN, ans = 0;
  for(int i = 0; i <= cnt; i++){
    cmp = std::max(cmp, sums[i]);
    if(cmp == sums[i]) ans = i;
  }
  cout << ans << endl;
  return 0;
}