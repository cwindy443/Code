#include <iostream>

int n, a, b, c;
const int MOD = 1e9 + 7, N = 2e5 + 5;
int ans;
int dp[N];

// void dfs(int num) {
//   if(num <= c) {
//     ans++;
//     ans %= MOD;
//     return;
//   }
//   dfs(num - a);
//   dfs(num - b);
// }

int main() {
  std::cin >> n >> a >> b >> c;
  
  if(n == c) {
    std::cout << 1 << std::endl;
    return 0;
  }
  dp[1] = 1;
  for(int i = 1; i <= n; i++) {
    dp[i + a] = dp[i + a] + a;
  }

  std::cout << ans << std::endl;

  return 0;
}