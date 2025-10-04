#include <bits/stdc++.h>

using namespace std;

int s, m;

int main(){
  cin >> s >> m;
  while(m--){
    int t;
    cin >> t;
    queue<int> q;
    int ans = 0;
    q.push(s);
    while(!q.empty()){
      int curr_t = q.front();
      q.pop();
      if(curr_t == s){
        cout << ans << endl;
        break;
      }
      q.push(
        
      );
    }
  }
  return 0;
}
