#include <iostream>
#include <stack>
#include <string>

typedef long long ll;

const ll lim = 1e12;
ll n, s;
int cnt;
std::string str;
std::stack<char> st;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> s;
  std::cin >> str;

  // reduce U with other 2 ops
  std::string reduced_ops;
  for (char op : str) {
    if (op == 'U') {
      if (!reduced_ops.empty() && reduced_ops.back() != 'U') {
        reduced_ops.pop_back();
      } else {
        reduced_ops.push_back(op);
      }
    } else {
      reduced_ops.push_back(op);
    }
  }

  // apply the reduced sequence of operations
  for (char op : reduced_ops) {
    if (op == 'U') {
      if (s > 1) {
        s /= 2;
      }
    } else if (op == 'L') {
      s *= 2;
    } else { 
      s = s * 2 + 1;
    }
  }
  
  std::cout << s << std::endl;

  return 0;
}