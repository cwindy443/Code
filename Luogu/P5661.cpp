#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
struct ticket{
  int t;
  int price;
  bool used;
}tkt[N];

int main(){
  cin >> n;
  int ans = 0;
  int head = 0, tail = -1;
  for(int i = 1; i <= n; i++){
    int p, trans, t;
    cin >> trans >> p >> t;
    if(trans == 0){
      ans += p;
      tkt[++tail] = {t + 45, p, 0};
    }
    else{
      while(head <= tail && tkt[head].t < t) head++;
      int f = 0;
      for(int j = head; j <= tail; j++){
        if (!tkt[j].used && tkt[j].price >= p) {
          tkt[j].used = 1;
          f = 1;
          break;
        }
      }
      if(!f) ans += p;
    }
  }
  cout << ans << endl;
  return 0;
}
