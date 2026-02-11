#include <iostream>

char mp[15][15];
bool vis[15][15];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int fx, fy, cx, cy;
  int fdir = 0, cdir = 0; // 0: N, 1: E, 2: S, 3: W
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};

  for(int i = 1; i <= 10; i++) {
    for(int j = 1; j <= 10; j++) {
      std::cin >> mp[i][j];
      if(mp[i][j] == '*') vis[i][j] = true;
      if(mp[i][j] == 'F') { fx = i; fy = j; }
      if(mp[i][j] == 'C') { cx = i; cy = j; }
    }
  }

  int time = 0;
  while (time <= 160000) {
    if (fx == cx && fy == cy) {
      std::cout << time << "\n";
      return 0;
    }

    // Move Farmer John
    int nfx = fx + dx[fdir];
    int nfy = fy + dy[fdir];
    if (nfx >= 1 && nfx <= 10 && nfy >= 1 && nfy <= 10 && !vis[nfx][nfy]) {
      fx = nfx;
      fy = nfy;
    } else {
      fdir = (fdir + 1) % 4;
    }

    // Move Cows
    int ncx = cx + dx[cdir];
    int ncy = cy + dy[cdir];
    if (ncx >= 1 && ncx <= 10 && ncy >= 1 && ncy <= 10 && !vis[ncx][ncy]) {
      cx = ncx;
      cy = ncy;
    } else {
      cdir = (cdir + 1) % 4;
    }
    
    time++;
  }
  
  std::cout << 0 << "\n";
  return 0;
}
