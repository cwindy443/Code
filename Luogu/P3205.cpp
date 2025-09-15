#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int MOD = 19650827;

int n;
int h[N];
// dp[i][j][0]: 形成 h[i..j] 区间，且最后一个加入的元素是 h[i] (从左边加入)
// 的方案数 dp[i][j][1]: 形成 h[i..j] 区间，且最后一个加入的元素是 h[j]
// (从右边加入) 的方案数
int dp[N][N][2];

int main() {
  // 快速 I/O
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }

  if (n <= 1) {
    cout << 1 << endl;
    return 0;
  }

  // 基本情况: 区间长度为 2
  for (int i = 1; i < n; i++) {
    if (h[i] < h[i + 1]) {
      // 初始序列 (h[i+1], h[i]) -> 最终序列 (h[i], h[i+1])
      dp[i][i + 1][0] = 1;
      // 初始序列 (h[i], h[i+1]) -> 最终序列 (h[i], h[i+1])
      dp[i][i + 1][1] = 1;
    }
  }

  // 填充 DP 表，区间长度从 3 到 n
  for (int len = 3; len <= n; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;

      // 计算 dp[i][j][0]: h[i] 是最后一个加入的元素
      // 前一个状态是区间 h[i+1..j]。上一个人的身高是 h[i+1] 或 h[j]。
      if (h[i] < h[i + 1]) {
        dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][0]) % MOD;
      }
      if (h[i] < h[j]) {
        dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][1]) % MOD;
      }

      // 计算 dp[i][j][1]: h[j] 是最后一个加入的元素
      // 前一个状态是区间 h[i..j-1]。上一个人的身高是 h[i] 或 h[j-1]。
      if (h[j] > h[i]) {
        dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][0]) % MOD;
      }
      if (h[j] > h[j - 1]) {
        dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][1]) % MOD;
      }
    }
  }

  int ans = (dp[1][n][0] + dp[1][n][1]) % MOD;
  cout << ans << endl;

  return 0;
}
