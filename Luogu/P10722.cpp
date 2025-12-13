#include <iostream>
#include <ostream>
#include <string>

const int N = 1e5 + 5;
int n, q;
int bt[N][2];
int opt[N];

void dfs(int x) {
  int l = bt[x][0], r = bt[x][1];
  if (opt[x])
    opt[l] ^= 1, opt[r] ^= 1;
  if (l)
    dfs(l);
  if (r)
    dfs(r);
}

int main() {
  std::cin.tie(nullptr);
  std::cin.sync_with_stdio(false);
  std::cout.sync_with_stdio(false);

  std::cin >> n;
  for (int i = 2; i <= n; i++) {
    int num;
    std::cin >> num;
    if (!bt[num][0])
      bt[num][0] = i;
    else
      bt[num][1] = i;
  }

  std::string color;
  std::cin >> color;
  color = "@" + color;
  std::cin >> q;

  for (int i = 1; i <= q; i++) {
    int op;
    std::cin >> op;
    opt[op] ^= 1;
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    int c = color[i] - '0';
    if (opt[i] == 1)
      std::cout << (c ^ 1);
    else
      std::cout << c;
  }
  std::cout << std::endl;
  return 0;
}
