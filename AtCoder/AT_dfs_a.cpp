#include <iostream>
#include <cstdlib>

using namespace std;

const int N = 505;
char mp[N][N];
int h, w;
bool vis[N][N];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void dfs(int x, int y){
  if (x < 1 || x > h || y < 1 || y > w || mp[x][y] == '#' || vis[x][y]) {
    return;
  }

  vis[x][y] = true;

  if(mp[x][y] == 'g'){
    cout << "Yes" << endl;
    exit(0);
  }

  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    dfs(nx, ny);
  }
}

int main(){
  cin >> h >> w;
  int sx, sy;
  for(int i = 1; i <= h; i++){
    for(int j = 1; j <= w; j++){
      cin >> mp[i][j];
      if(mp[i][j] == 's'){
        sx = i, sy = j;
      }
    }
  }

  dfs(sx, sy);

  cout << "No" << endl;

  return 0;
}
