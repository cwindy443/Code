#include <iostream>
#include <string>
using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  int x = 0;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    for(int j = 0; j < str.size(); j++) {
      if(str[j] == '+' && str[j + 1] == '+') {
        x++;
      } else if(str[j] == '-' && str[j + 1] == '-'){
        x--;
      }
    }
  } 
  cout << x << endl;
  return 0;
}
