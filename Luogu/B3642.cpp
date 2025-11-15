#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int n;
struct Node{
  int l, r;
};

std::pmr::vector<Node> point;

void front(){
  
}

void middle(){

}

void back(){

}

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    int left, right;
    cin >> left >> right;
    point.push_back({left, right});
  }
  front();
  cout << endl;
  middle();
  cout << endl;
  back();
  cout << endl;
  return 0;
}