#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
  cin >> s;
  int len = s.size();
  for(int i = 0; i < len - 1; i++){
    if(s[i] > s[i + 1]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
