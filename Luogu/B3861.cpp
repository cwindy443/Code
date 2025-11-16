#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int N = 1e3 + 5;
int n;
int fa[N], cnt[N];

int main(){
  cin.tie(0);
  cin.sync_with_stdio(NULL);

  cin >> n;
  cnt[1] = 1;
  for(int i = 2; i <= n; i++){
    cin >> fa[i];
    cnt[i] = 1;
  }
  for(int i = n; i >= 1; i--){
    cnt[fa[i]] += cnt[i];
  }
  for(int i = 1; i <= n; i++){
    cout << cnt[i] << endl;
  }
  return 0;
}