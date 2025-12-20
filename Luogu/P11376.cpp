#include <iostream>
#include <algorithm>
typedef long long ll;

const int NM = 1e5 + 5;
int n, m, x;

struct Node {
  int p, c;
}trans[NM];

struct Truck {
  int a, b, diff;
}truck[NM];

bool cmp1(Node x, Node y) {
  return x.p < y.p;
}

bool cmp2(Truck x, Truck y) {
  return x.diff > y.diff;
}

int main() {
  std::cin.tie(nullptr);
  std::cin.sync_with_stdio(false);
  std::cout.sync_with_stdio(false);

  std::cin >> n >> m >> x;
  for(int i = 1; i <= n; i++) {
    std::cin >> trans[i].p >> trans[i].c;
  }
  std::sort(trans + 1, trans + 1 + n, cmp1);

  int tot = 0;
  for(int i = 1; i <= m; i++) {
    std::cin >> truck[i].a >> truck[i].b;
    truck[i].diff = std::abs(truck[i].a - truck[i].b);
    tot += 2 * truck[i].b * x;
  }
  std::sort(truck + 1, truck + 1 + m, cmp2);
 
  ll min_dynamic = 0;
  int station_idx = 0;
  for (int i = 0; i < m; ++i) {
      // 找到还有容量的站点
      while (stations[station_idx].c == 0) {
        station_idx++;
      }
      min_dynamic += 2LL * stations[station_idx].p * w[i];
      stations[station_idx].c--;
  }

  std::cout << min_dynamic + total_constant << std::endl;
  return 0;
}