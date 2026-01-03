#include <iostream>
#include <cstring>

int f[1005];
int cost[105], got[105];
int dp[10005];
int n, gold;

// void dp1() {
//   for(int i = 1; i <= n; i++) {
//     for(int j = T; j >= cost[i]; j--) {
//       f[j] = std::max(f[j - cost[i]] + got[i], f[j]);
//     }
//   }
//   for(int i = 1; i <= T; i++) std::cout << f[i] << " ";
//   std::cout << std::endl;
// }

void dp2() { 
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 250000; j >= got[i]; j--) {
      dp[j] = std::min(dp[j - got[i]] + cost[i], dp[j]);
    }
  }
  int ans = -1;
  for(int i = 1; i <= 505; i++) ans = std::max(ans, dp[i]);
  std::cout << ans << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> gold;
  for(int i = 1; i <= n; i++) {
    std::cin >> got[i] >> cost[i];
  }
  //dp1();
  dp2();
  return 0;
}