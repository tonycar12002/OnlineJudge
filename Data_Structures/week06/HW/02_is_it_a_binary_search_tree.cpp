#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsTreeInRange(const vector<Node>& tree, int root, int range_min, int range_max){
  int key = tree[root].key;
  int left = tree[root].left;
  int right = tree[root].right;
  if( key < range_min || key > range_max ){
    return false;
  }
  else{
    bool left_in_range = true, right_in_range = true;
    if( left != -1 ){
      left_in_range = IsTreeInRange(tree, left, key, range_min);
    }
    if ( right != -1 ){
      right_in_range = IsTreeInRange(tree, right, range_max, key);
    }
    return left_in_range && right_in_range;
  }
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  int min = tree[tree[0].left].key;
  int max = tree[tree[0].right].key;
  if(min == -1)
    min = -2147483647;
  if(max == -1)
    max = 2147483647;
  return IsTreeInRange(tree, 0, min, max);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if(nodes == 0){
    cout << "CORRECT" <<endl;
  }
  else if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
