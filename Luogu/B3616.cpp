#include <iostream>
#include <queue>

using namespace std;
const int N = 1e6 + 5;

int main() {
  int n;
  cin >> n;
  queue<int> q;
  while (n--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      cin >> x;
      q.push(x);
    } else if (op == 2) {
      if (q.empty())
        cout << "ERR_CANNOT_POP" << endl;
      else
        q.pop();
    } else if (op == 3) {
      if (q.empty())
        cout << "ERR_CANNOT_QUERY" << endl;
      else
        cout << q.front() << endl;
    } else
      cout << q.size() << endl;
  }
  return 0;
}