#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e6 + 5;
int m;
int sums[N];
struct answer{
  int x;
  int y;
};
vector<answer> ans;
bool cmp(answer x, answer y){
  return x.x < y.x;
}

signed main(){
  cin >> m;
  for(int k = 1; k <= m; k++){
    sums[k] = sums[k - 1] + k;
  }
  int i = 1, j = 2;
  while (i <= m / 2) {
    if (j <= i) {
        j = i + 1;
    }
    long long current_sum = sums[j] - sums[i - 1];
    if (current_sum < m) {
        j++;
    } else if (current_sum > m) {
        i++;
    } else {
        ans.push_back({i, j});
        i++;
    }
  }
  for(auto it = ans.begin(); it != ans.end(); it++){
    cout << it->x << " " << it->y << endl;
  }
  return 0;
}
