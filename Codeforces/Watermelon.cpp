#include <iostream>
using namespace std;

int w;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> w;
  for(int i = 2; i <= w / 2; i += 2) {
    if((w - i) % 2 == 0) {
      cout << "YES" << endl;
      return 0;
    } 
  }
  cout << "NO" << endl;
  return 0;
}
