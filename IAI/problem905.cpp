#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= n / 3; i++) {
    for (int j = i; j <= (n - i) / 2; j++) {
      int k = n - i - j;
      cout << i << " " << j << " " << k << endl;
    }
  }
  return 0;
}
