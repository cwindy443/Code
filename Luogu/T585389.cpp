#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

string A, B;

int extend(queue<int> &q, int *da, int *db) {
  int level = da[q.front()]; // present level of bfs
  while (q.size() && level == da[q.front()]) {
    int x = q.front();
    q.pop();

    // +1
    string sx1 = to_string(x);
    for (int i = 0; i < 4; i++) {
      string sy1 = sx1;
      sy1[i]++;
      if (sy1[i] > '9')
        sy1[i] = '1';
      int y = stoi(sy1); // y == int(some_level + 1)
      if (db[y] != -1) { // visb[y] == 1
        // if answer
        return db[y] + da[x] + 1;
      } else if (da[y] == -1) {
        q.push(y);
        da[y] = da[x] + 1;
      }
    }

    // -1
    string sx2 = to_string(x);
    for (int i = 0; i < 4; i++) {
      string sy2 = sx2;
      sy2[i]--;
      if (sy2[i] < '1')
        sy2[i] = '9';
      int y = stoi(sy2);
      if (db[y] != -1) {
        return db[y] + da[x] + 1;
      } else if (da[y] == -1) {
        q.push(y);
        da[y] = da[x] + 1;
      }
    }

    // swap
    string sx3 = to_string(x);
    for (int i = 1; i < 4; i++) {
      string sy3 = sx3;
      swap(sy3[i], sy3[i - 1]);
      int y = stoi(sy3);
      if (db[y] != -1) {
        return db[y] + da[x] + 1;
      } else if (da[y] == -1) {
        q.push(y);
        da[y] = da[x] + 1;
      }
    }
  }
  return -1;
}

int bfs() {
  if (A == B)
    return 0;

  queue<int> qa, qb;            // save BFS
  int disa[10005], disb[10005]; // record distance to the start
  memset(disa, -1, sizeof(disa));
  memset(disb, -1, sizeof(disb));
  int a = stoi(A), b = stoi(B);
  qa.push(a), qb.push(b);
  disa[a] = disb[b] = 0;

  while (qa.size() && qb.size()) {
    int ans = 0;
    if (qa.size() < qb.size()) {
      ans = extend(qa, disa, disb); // extend A
    } else {
      ans = extend(qb, disb, disa); // extend B
    }
    if (ans > 0)
      return ans;
  }
  return 0;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> A >> B;
    cout << bfs() << endl;
  }
  return 0;
}