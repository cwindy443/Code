#include <iostream>

using namespace std;

int n;
char vis[15];

void dfs(int cnt){
  if(cnt == n + 1){
    for(int i = 1; i <= n; i++)
      cout << vis[i];
    cout << endl;
    return;
  }
  for(int i = 0; i < 2; i++){
    vis[cnt] = (i == 0 ? 'N' : 'Y');
    dfs(cnt + 1);
  }
}

int main(){
  cin >> n;
  dfs(1);
  return 0;
}
