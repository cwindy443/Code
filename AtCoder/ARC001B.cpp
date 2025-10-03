#include <bits/stdc++.h>

using namespace std;

int a, b;

int main(){
  cin >> a >> b;
  int diff = abs(a - b);
  int cnt = diff / 10, rest = diff % 10;
  if(rest == 1 || rest == 5){
    cnt++;
  }else if(rest == 2 || rest == 4 || rest == 6 || rest == 9){
    cnt += 2;
  }else if(rest == 3 || rest == 7 || rest == 8){
    cnt += 3;
  }
  cout << cnt << endl;
  return 0;
}
