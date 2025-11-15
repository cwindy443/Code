#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int n;
struct Node{
  int l, r;
};

std::vector<Node> tree;

void preOrder(int root){
  if(root == 0) return;
  cout << root << " ";
  preOrder(tree[root].l);
  preOrder(tree[root].r);
}

void inOrder(int root){
  if(root == 0) return;
  inOrder(tree[root].l);
  cout << root << " ";
  inOrder(tree[root].r);
}

void postOrder(int root){
  if(root == 0) return;
  postOrder(tree[root].l);
  postOrder(tree[root].r);
  cout << root << " ";
}

int main(){
  cin >> n;
  tree.resize(n + 1);
  for(int i = 1; i <= n; i++){
    int left, right;
    cin >> left >> right;
    tree[i] = {left, right};
  }
  preOrder(1);
  cout << endl;
  inOrder(1);
  cout << endl;
  postOrder(1);
  cout << endl;
  return 0;
}