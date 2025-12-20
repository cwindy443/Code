#include <iostream>
#include <vector>
#include <climits>
typedef long long ll;

const int N = 2e5 + 5;
int n;
ll l[N], s[N];
std::vector<ll> a;

int main() {
  std::cin.tie(nullptr);
  std::cin.sync_with_stdio(false);  
  std::cout.sync_with_stdio(false);

  std::cin >> n;
  for(int i = 1; i <= n; i++) {
    int num;
    std::cin >> num;
    a.push_back(num);
  }
  ll sum = 0, maxx = INT_MIN;
  for(int i = 0; i < n; i++) {
    sum += a[i];
    maxx = std::max(maxx, a[i]);
    l[i + 1] = std::max(l[i + 1], l[i] + a[i]);
    s[i + 1] = std::min(s[i + 1], s[i] + a[i]);
  }
  ll ans = INT_MIN;
  for (int i = 0; i < n; i++) {
    ans = std::max(ans, std::max(l[i], sum - s[i]));
  }
  
  std::cout << (ans == 0 ? maxx : ans) << std::endl;
  return 0;
}