#include <iostream>
#include <vector>
#include <set>
#include <string>

typedef long long ll;

const int N = 1e5 + 5;
std::vector<ll> a;
int n;
std::string s;
ll dp[N];

int main() {
  std::cin.tie(nullptr);
  std::cin.sync_with_stdio(false);
  std::cout.sync_with_stdio(false);

  std::cin >> n >> s;
  for(int i = 1; i <= n; i++) {
    int num;
    std::cin >> num;
    a.push_back(num);
  }

  dp[0] = a[0];
  for(int i = 1; i < n; i++) {
    dp[i] = dp[i - 1] + a[0];
    std::set<char> st;
    st.insert(s[i]);
    for(int j = i - 1; j >= 0; j--) {
      if(st.count(s[j])) break;
      st.insert(s[j]);
      if(j == 0) dp[i] = std::max(dp[i], a[i]);
      else dp[i] = std::max(dp[i], dp[j - 1] + a[i - j]);
    }
  }
  std::cout << dp[n - 1] << std::endl;
  return 0;
}