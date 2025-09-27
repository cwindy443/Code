#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  vector<int> a={1, 2, 3};
  do{
    for(int num : a){
      cout << num << " ";
    }
    cout << endl;
  }while(next_permutation(a.begin(), a.end()));
}
