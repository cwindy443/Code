#include <iostream>

int n, m;

struct edge{
  int y, v, next;
}e[200005];

int len = 0;
int head[1005];

inline void addEdge(int x, int y){
  e[++len].y = y;// save the data of new edge
  e[len].next = head[x]; //head-insertion: point new edge to head[x]
  head[x] = len;
}

int main(){
  std::cin >> n >> m;
  for(int i = 1; i <= m; i++){
    int x, y;
    std::cin >> x >> y;
    addEdge(x, y);
    addEdge(y, x);
  }
}