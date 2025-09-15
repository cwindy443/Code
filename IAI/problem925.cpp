#include <bits/stdc++.h>

using namespace std;

int main() {
  char ch;
  cin >> ch;
  if (ch >= '0' && ch <= '9') {
    cout << char('9' - ch + '0') << endl;
  } else if (ch >= 'A' && ch <= 'Z') {
    cout << char('Z' - ch + 'A') << endl;
  } else if (ch >= 'a' && ch <= 'z') {
    cout << char('z' - ch + 'a') << endl;
  }
  return 0;
}
