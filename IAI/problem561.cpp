#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
char a[N];
stack<char> ch;

int main() {
  int n = 0;
  char c;
  while (cin >> c) {
    a[++n] = c;
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] == '(' || a[i] == '[')
      ch.push(a[i]);
    else if (a[i] == ')') {
      if (ch.empty()) {
        cout << "Unbalanced" << endl;
        return 0;
      } else if (ch.top() == '(')
        ch.pop();
      else {
        cout << "Unbalanced" << endl;
        return 0;
      }

    }

    else if (a[i] == ']') {
      if (ch.empty()) {
        cout << "Unbalanced" << endl;
        return 0;
      } else if (ch.top() == '[')
        ch.pop();
      else {
        cout << "Unbalanced" << endl;
        return 0;
      }
    } else
      ch.pop();
  }
  if (ch.size() != 0)
    cout << "Unbalanced" << endl;
  else
    cout << "Balanced" << endl;

  return 0;
}
