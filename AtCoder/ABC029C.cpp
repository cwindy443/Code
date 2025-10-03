#include <iostream>

using namespace std;

int n;
char a[10];

void dfs(int cnt){
  if(cnt == n + 1){
    for(int i = 1; i <= n; i++){
      cout << a[i];
    }
    cout << endl;
    return;
  }
  for(int i = 1; i <= 3; i++){
    a[cnt] = 'a' + i - 1;
    dfs(cnt + 1);
  }
}

int main(){
  cin >> n;
  dfs(1);
  return 0;
}
