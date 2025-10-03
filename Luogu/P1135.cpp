#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;

    if (a == b) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> k(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;

    q.push(a);
    dist[a] = 0;

    while (!q.empty()) {
        int curr_floor = q.front();
        q.pop();

        int up_floor = curr_floor + k[curr_floor];
        int down_floor = curr_floor - k[curr_floor];

        if (up_floor <= n && dist[up_floor] == -1) {
            dist[up_floor] = dist[curr_floor] + 1;
            if (up_floor == b) {
                cout << dist[b] << endl;
                return 0;
            }
            q.push(up_floor);
        }

        if (down_floor >= 1 && dist[down_floor] == -1) {
            dist[down_floor] = dist[curr_floor] + 1;
            if (down_floor == b) {
                cout << dist[b] << endl;
                return 0;
            }
            q.push(down_floor);
        }
    }

    cout << -1 << endl;

    return 0;
}
