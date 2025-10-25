#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>

const int N = 5e4 + 5;
int n, k, c;
struct dog {
  int s, e, m;
} a[N];

bool cmp(dog x, dog y) {
  if (x.e != y.e)
    return x.e < y.e;
  return x.s < y.s;
}

int main() {
  freopen("dog.in", "r", stdin);
  freopen("dog.out", "w", stdout);
  std::cin >> n >> k >> c;
  for (int i = 1; i <= k; i++) {
    std::cin >> a[i].s >> a[i].e >> a[i].m;
  }
  std::sort(a + 1, a + 1 + k, cmp);

  int ans = 0;
  std::multiset<int> walkers_end_time;
  for (int i = 0; i < c; ++i) {
    walkers_end_time.insert(0);
  }

  for (int i = 1; i <= k; i++) {
    auto it = walkers_end_time.upper_bound(a[i].s);

    if (it != walkers_end_time.begin()) {
      it--;
      walkers_end_time.erase(it);
      walkers_end_time.insert(a[i].e);
      ans++;
    }
  }

  std::cout << ans << std::endl;

  fclose(stdin);
  fclose(stdout);
  return 0;
}
