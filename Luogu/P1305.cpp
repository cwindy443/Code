#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int n;
struct Node{
  char id;
  char lc;
  char rc;
};
std::vector<Node> v;

void preOrder(int root){
  if(root == 0) return;
  cout << v[root].id;
  preOrder(v[root].lc);
  preOrder(v[root].rc);
}

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    std::string s;
    cin >> s;
    v[i] = {s[0], s[1], s[2]};
  }
  preOrder(1);
  return 0;
}