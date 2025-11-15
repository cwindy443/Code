#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int n;
struct Node{
  int l, r;
  int high;
}tree[];


int dfs(int x, int op){
  if(x == 0) return;
  if(op == 1) cout << x << " ";
  dfs(tree[x].l, op);
  if(op == 2) cout << x << " ";
  dfs(tree[x].r, op);
  if(op == 3) cout << x << " "; 
}

int main(){
  cin.tie(0);
  cin.sync_with_stdio(NULL);
  cin >> n;
  
  return 0;
}