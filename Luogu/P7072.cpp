#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int N = 600 + 7;
int n, w;
int cnt[N];

int main(){
  cin >> n >> w;
  for(int i = 1; i <= n; i++){
    int num;
    cin >> num;
    cnt[num]++;
    int ranking = max(1, (int) floor(1.0 * i * w / 100));
    int sum = 0, score = 0;
    for(int i = 600; i >= 0; i--){
      sum += cnt[i];
      if(sum >= ranking){
        cout << i << " ";
        break;
      }
    }
  }

  return 0;
}
