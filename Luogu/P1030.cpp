#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct Node{
  int l, r;
}t[1000005];
int n;
int depth[1000005];

void dfs(int x){
  if(x == 0) return;
  depth[t[x].l] = depth[x] + 1;
  depth[t[x].r] = depth[x] + 1;
  dfs(t[x].l);
  dfs(t[x].r);
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(NULL);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> t[i].l >> t[i].r;
  }
  dfs(1);
  return 0;
}