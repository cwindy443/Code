#include <iostream>
#include <vector>
#include <queue>
#include <utility>

const int N = 2e5 + 5;
const int M = 2e5 + 5;

int head[N];
std::vector<int> dis(N, -1);
struct edge
{
  int next, y, v;
}e[2 * M];
int id;

void insert(int x, int y, int v){
  e[++id].y = y;
  e[id].v = v;
  e[id].next = head[x];
  head[x] = id;
}

int n;
int cnt[2];

void dfs(int x){
  for(int i = head[x]; i; i = e[i].next){
    int y = e[i].y;
    if(dis[y] == -1){
      dis[y] = dis[x] + 1;
      cnt[dis[y] & 1]++;
      dfs(y);
    }
  }
}

// void bfs(int st){
//   std::queue<int> q;
//   q.push(st);
//   while (!q.empty())
//   {
//     int x = q.front();
//     q.pop();
//     for(int i = head[x]; i; i = e[i].next){
//       int y = e[i].y;
//       if(dis[y] == -1){
//         dis[y] = dis[x] + 1;
//         q.push(y);
//       }
//     }
//   }
// }

int main(){
  std::cin.tie(NULL);
  std::cin.sync_with_stdio(false);
  std::cin >> n;
  for(int i = 1; i < n; i++){
    int u, v;
    std::cin >> u >> v;
    insert(u, v, 1);
    insert(v, u, 1);
  }
  dis[1] = 0;
  cnt[0] = 1;
  dfs(1);
  for(int i = 1; i <= n; i++){
    std::cout << cnt[dis[i] & 1] << " ";
  }
  std::cout << std::endl;
  return 0;
}