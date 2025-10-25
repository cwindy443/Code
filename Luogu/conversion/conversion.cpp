#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
int c, T;
vector<string> a;

int main(){
  freopen("conversion.in", "r", stdin);
  freopen("conversion.out", "w", stdout);

  cin >> c >> T;
  while(T--){
    string s;
    cin >> s;
    for(int i = s.size() - 1; i >= 0; i--){
      if(s[i] == ','){
        s = s.substr(i, s.size() - i);
        break;
      }
    }
    int pre = 0;
    for(int i = 0; i < s.size(); i++){
      if(s[i] == '*' || s[i] == '+'){
        a.push_back(s.substr(pre, i - pre));
        pre = i + 1;
      }
    }
    a.push_back(s.substr(pre, s.size() - pre));
    if(a.size() == 1){
      cout << a[1] << endl;
      continue;
    }
    for(int i = 0; i <= a.end() - a.begin(); i++){
      if(a[i] == a[i + 1]){
        a.push_back(a[i]);
      }
      if(a[i] == "bool" || a[i] == "char") a[i] = "int";
      if(a[i] == "int"){
        if(a[i + 1] == "longlong"){
          a.push_back("longlong");
        }
        else if(a[i + 1] == "float"){
          a.push_back("float");
        }
        else if(a[i + 1] == "double"){
          a.push_back("double");
        }
        else{
          a.push_back("int");
        }
      }
      else if(a[i] == "longlong"){
        if(a[i + 1] == "float"){
          a.push_back("float");
        }
        else if(a[i + 1] == "double"){
          a.push_back("double");
        }
        else{
          a.push_back("longlong");
        }
      }
      else if(a[i] == "float"){
        if(a[i + 1] == "double"){
          a.push_back("double");
        }
        else{
          a.push_back("float");
        }
      }
      else{
        a.push_back("double");
      }
    }
    for(auto it = a.begin(); it != a.end(); it++) cout << *it << endl;
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}
