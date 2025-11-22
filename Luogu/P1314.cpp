#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

typedef long long ll;
typedef __int128_t i128;

const int N = 2e5 + 5;
int n;
ll m, s;
std::vector<int> w(N), v(N);
std::vector<ll> sums(N), cnt(N);
std::vector<int> qs1(N), qs2(N);

i128 check(int W){
  for(int i = 1; i <= n; i++){
    cnt[i] = cnt[i - 1];
    sums[i] = sums[i - 1];
    if(w[i] >= W){
      cnt[i]++;
      sums[i] += v[i];
    }
  }
  i128 t = 0;
  for(int i = 1; i <= m; i++){
    int l = qs1[i], r = qs2[i];
    t += (i128)(cnt[r] - cnt[l - 1]) * (sums[r] - sums[l - 1]);
  }
  return t;
}

i128 abs128(i128 n) {
    return n > 0 ? n : -n;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> s;

  int min_w = 2e9, max_w = 0;
  for(int i = 1; i <= n; i++){
    cin >> w[i] >> v[i];
    min_w = std::min(min_w, w[i]);
    max_w = std::max(max_w, w[i]);
  }
  for(int i = 1; i <= m; i++){
    cin >> qs1[i] >> qs2[i];
  }

  int l = 0, r = max_w + 1;
  i128 min_diff = -1;

  while(l <= r){
    int mid = l + (r - l) / 2;
    if (mid > max_w + 1) mid = max_w + 1;
    if (mid < 0) mid = 0;
    
    i128 y = check(mid);
    i128 diff = abs128(y - s);

    if (min_diff == -1 || diff < min_diff) {
        min_diff = diff;
    }
    
    if(y > s) {
      l = mid + 1;
    } else if (y < s) {
      r = mid - 1;
    } else {
      min_diff = 0;
      break;
    }
  }
  
  cout << (ll)min_diff << endl;
  
  return 0;
}