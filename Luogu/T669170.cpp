#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
struct surface{
  int h, l, r, num;
}a[N];

struct ans{
  int l, r;
}fin_ans[N];

int n;
bool cmp1(surface x, surface y){
  if(x.h != y.h) return x.h > y.h;
  return x.num < y.num;
}

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i].h >> a[i].l >> a[i].r;
    a[i].num = i;
  }
  sort(a + 1, a + 1 + n, cmp1);

  for(int i = 1; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      if(a[j].l < a[i].l && a[j].r > a[i].l && a[j].h < a[i].h){
        fin_ans[a[i].num].l = a[j].num;
        break;
      }
    }
    for(int j = i + 1; j <= n; j++){
      if(a[j].l < a[i].r && a[j].r > a[i].r && a[j].h < a[i].h){
        fin_ans[a[i].num].r = a[j].num;
        break;
      }
    }
  }
  for(int i = 1; i <= n; i++) cout << fin_ans[i].l << " " << fin_ans[i].r << endl;
  return 0;
}
