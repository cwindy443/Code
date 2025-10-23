#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
  freopen("math.in", "r", stdin);
  freopen("math.out", "w", stdout);

  cin >> T;
  while(T--){
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cout << 0 << endl;
    } else if (a < b) {
      int diff = b - a;
      if (diff % 2 != 0) {
        cout << 1 << endl;
      } else {
        if (diff % 4 == 0) {
          cout << 3 << endl;
        } else {
          cout << 2 << endl;
        }
      }
    } else {
      int diff = a - b;
      if (diff % 2 == 0) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}
