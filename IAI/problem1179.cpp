#include <iostream>
#include <string>
#include <vector>

typedef long long ll;
const ll MOD = 998244353;

// 大整数乘法（字符串形式）
std::string multiplyStrings(const std::string &a, const std::string &b) {
  int n = a.size();
  int m = b.size();
  std::vector<int> result(n + m, 0);

  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      int mul = (a[i] - '0') * (b[j] - '0');
      int p1 = i + j;
      int p2 = i + j + 1;
      int sum = mul + result[p2];

      result[p2] = sum % 10;
      result[p1] += sum / 10;
    }
  }

  std::string str;
  for (int i = 0; i < result.size(); i++) {
    if (!(str.empty() && result[i] == 0)) {
      str += (char)('0' + result[i]);
    }
  }

  return str.empty() ? "0" : str;
}

// 将字符串转换为数字对MOD取模
ll stringToModll(const std::string &s) {
  ll result = 0;
  for (char c : s) {
    result = (result * 10 + (c - '0')) % MOD;
  }
  return result;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::string a, b;
  std::cin >> n >> a >> b;

  std::vector<int> a_digits(n), b_digits(n);

  for (int i = 0; i < n; i++) {
    a_digits[i] = a[i] - '0';
    b_digits[i] = b[i] - '0';
  }

  std::vector<int> a_result(n), b_result(n);

  // 处理首位
  int a_first = a_digits[0];
  int b_first = b_digits[0];

  if (a_first <= b_first) {
    a_result[0] = a_first;
    b_result[0] = b_first;
  } else {
    a_result[0] = b_first;
    b_result[0] = a_first;
  }

  // 处理其他位：贪心地选择较小的给a
  for (int i = 1; i < n; i++) {
    int a_dig = a_digits[i];
    int b_dig = b_digits[i];
    if (a_dig <= b_dig) {
      a_result[i] = a_dig;
      b_result[i] = b_dig;
    } else {
      a_result[i] = b_dig;
      b_result[i] = a_dig;
    }
  }

  // 构建字符串
  std::string a_str, b_str;
  for (int i = 0; i < n; i++) {
    a_str += (char)('0' + a_result[i]);
    b_str += (char)('0' + b_result[i]);
  }

  // 计算乘积
  std::string product = multiplyStrings(a_str, b_str);

  // 转换为MOD
  ll answer = stringToModll(product);

  std::cout << answer << std::endl;

  return 0;
}
