#include <bits/stdc++.h>

using namespace std;

struct node {
  int x, y;
} st, ed;

int l;
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dis[2][301][301];

int extend(queue<node> &q, int a, int b) {
  auto t = q.front();
  int d = dis[a][t.x][t.y];
  while (q.size() && d == dis[a][q.front().x][q.front().y]) {
    t = q.front();
    q.pop();
    for (int i = 1; i < 8; i++) {
      int nx = t.x + dx[i], ny = t.y + dy[i];
      if (nx < 0 || nx > l || ny < 0 || ny > l)
        continue;
      if (dis[b][nx][ny] != -1) {
        return dis[b][nx][ny] + dis[a][t.x][t.y] + 1;
      } else if (dis[a][nx][ny] != -1) {
        continue;
      }
      dis[a][nx][ny] = dis[a][t.x][t.y] + 1;
      q.push({nx, ny});
    }
  }
  return 0;
}

int bfs() {
  if (st.x == ed.x && st.y == ed.y)
    return 0;

  queue<node> q1, q2;
  memset(dis, -1, sizeof(dis));
  dis[0][st.x][st.y] = dis[1][ed.x][ed.y] = 0;
  q1.push(st), q2.push(ed);
  int ans = 0;
  while (q1.size() && q2.size()) {
    if (q1.size() <= q2.size()) {
      ans = extend(q1, 0, 1);
    } else {
      ans = extend(q2, 1, 0);
    }
    if (ans > 0)
      return ans;
  }
  return 0;
}

int main() {
  int Q;
  cin >> Q;
  while (Q--) {
    cin >> l;
    cin >> st.x >> st.y >> ed.x >> ed.y;
    cout << bfs() << endl;
  }
  return 0;
}