#include <iostream>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  int tot_five = 0;

  while (n % 5 == n) {
    tot_five++;
    n -= 5;
  }
  cout << tot_five << endl;
  return 0;
}
