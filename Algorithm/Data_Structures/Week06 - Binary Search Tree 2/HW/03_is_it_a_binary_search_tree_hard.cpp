   #include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  long long int key;
  long long int left;
  long long int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long long int key_, long long int left_, long long int right_) : key(key_), left(left_), right(right_) {}
};

bool IsTreeInRange(const vector<Node>& tree, long long int root, long long int range_min, long long int range_max){
  long long int key = tree[root].key;
  long long int left = tree[root].left;
  long long int right = tree[root].right;
  if( key < range_min || key >= range_max ){
    return false;
  }
  else{
    bool left_in_range = true, right_in_range = true;
    if( left != -1 ){
      left_in_range = IsTreeInRange(tree, left, range_min, key);
    }
    if ( right != -1 ){
      right_in_range = IsTreeInRange(tree, right, key, range_max);
    }
    return left_in_range && right_in_range;
  }
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  return IsTreeInRange(tree, 0, -2147483699, 2147483699);
}

int main() {
  long long int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (long long int i = 0; i < nodes; ++i) {
    long long int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }

  if(nodes == 0 || nodes == 1){
    cout << "CORRECT" <<endl;
  }
  else if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
