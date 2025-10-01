#include <bits/stdc++.h>

using namespace std;

set<string> s;
int n;

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    string str;
    cin >> str;
    s.insert(str);
  }
  int ans = 0;
  for(auto it = s.begin(); it != s.end(); it++){
    if(*it != "\0") ans++;
  }
  cout << 52 - ans << endl;
  return 0;
}
