#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int mp[35][35];
bool visited[35][35];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(int start_x, int start_y) {
    if (mp[start_x][start_y] != 0 || visited[start_x][start_y]) {
        return;
    }

    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && mp[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mp[i][j];
        }
    }

    // Start BFS from all boundary '0's to find the outside area
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 || i == n || j == 1 || j == n) {
                if (mp[i][j] == 0) {
                    bfs(i, j);
                }
            }
        }
    }

    // Fill the inside '0's and print the result
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (mp[i][j] == 0 && !visited[i][j]) {
                cout << 2 << 