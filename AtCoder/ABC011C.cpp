#include <iostream>

using namespace std;

int n, ng1, ng2, ng3;
int p = 100;

int main(){
  cin >> n;
  cin >> ng1 >> ng2 >> ng3;

  if(n == ng1 || n == ng2 || n == ng3){
    cout << "NO" << endl;
    return 0;
  }
  while(n > 0 && p){
    p--;
    if(n - 3 >= 0 && n - 3 != ng1 && n - 3 != ng2 && n - 3 != ng3){
      n -= 3;
    }
    else if(n - 2 >= 0 && n - 2 != ng1 && n - 2 != ng2 && n - 2 != ng3){
      n -= 2;
    }
    else if(n - 1 >= 0 && n - 1 != ng1 && n - 1 != ng2 && n - 1 != ng3){
      n -= 1;
    }
    else{
      break;
    }
    if(n == 0){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << n << endl;
  cout << "NO" << endl;
  return 0;
}
