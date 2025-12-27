#include <iostream>
#include <stdio.h>
#include <cmath>

const int N = 1e5 + 5;
int n;
int x[N], p[N];
double q;

int main() {
  std::cin >> n;
  for(int i = 1; i <= n; i++) {
    std::cin >> x[i];
  }
  double E = 0;
  for(int i = 1; i <= n; i++) {
    std::cin >> p[i];
    E += x[i] * p[i];
    q += p[i];
  }
  E /= q;
  double u = 0;
  for(int i = 1; i <= n; i++) {
    u += (pow(abs(x[i] - E), 2) * p[i]) / q;
  }
  printf("%.3lf\n%.3lf", E, u);
  return 0;
}