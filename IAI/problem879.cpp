#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  cin >> n >> m;

  long long n_ll = n;
  long long m_ll = m;

  long long odd_rows = (n_ll + 1) / 2;
  long long even_rows = n_ll / 2;
  long long ans = odd_rows * m_ll + even_rows * (m_ll / 2);
  cout << ans << endl;
  return 0;
}
