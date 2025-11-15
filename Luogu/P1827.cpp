#include <bits/stdc++.h>

using namespace std;

string s1, s2;
void dfs(int x, int y, int a, int b){
  if(x > y || a > b) return;
  for(int i = x; i <= y; i++){
    if(s1[i] == s2[a]){ // find root
      dfs(x, i - 1, a + 1, a + i - x); //left
      dfs(i + 1, y, a + i - x + 1, b); //right
      cout << s1[i];
    }
  }
}

int main(){
  cin >> s1 >> s2;
  int n = s1.size();
  dfs(0, n - 1, 0, n - 1);  
  return 0;
}