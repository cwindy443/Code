#include <algorithm>
#include <iostream>

const int N = 2e5 + 5;
int n, x, y, z;
int a[N];
bool vis[4];

bool cmp(int n, int m) {
  return n > m;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int idx = 1;
  std::cin >> n >> x >> y >> z;
  for(int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a + idx, a + idx + n, cmp);
  for(int i = 1; i <= n; i++) { 
    if(a[i] % x == 0) {
      vis[1] = true;
      idx = i;
    }
  }
  return 0;
}