#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
class Vertex{
public:
  long long int key;
  long long int sum;
  Vertex* left;
  Vertex* right;
  Vertex* parent;

  Vertex():left(NULL), right(NULL), parent(NULL), sum(0){}
  Vertex(long long int k, Vertex* par):left(NULL), right(NULL), parent(par), key(k), sum(0){}
  ~Vertex(){}
};
class SplayTree{
private:
  Vertex* root;
  long long int last_sum ;

public:
  SplayTree():root(NULL), last_sum(0){}
  ~SplayTree(){}

  long long int getLastSum(){return last_sum;}

  void remove(long long int key){
    Vertex *search_vertex = searchVertex(key);
    splay(search_vertex);
    if(!root || root->key != key)
      return;
    else{
      Vertex *left_subtree_root = search_vertex->left;
      Vertex *min_root_right_subtree;
      if(search_vertex->right){
        search_vertex->right->parent = NULL;
        root = search_vertex->right;
        min_root_right_subtree = searchVertex(-1);
        splay(min_root_right_subtree);
        min_root_right_subtree->left = left_subtree_root;
        root = min_root_right_subtree;
        if(left_subtree_root){
          left_subtree_root->parent = root;
          root->sum += left_subtree_root->sum;
        }
      }
      else if(search_vertex->left){
        search_vertex->left->parent = NULL;
        root = search_vertex->left;
      }
      else
        root = NULL;
    }
  }


  void sum(long long int left, long long int right){

    if(!root){
      last_sum = 0;
      cout << last_sum << endl;
      return;
    }
    long long int left_sum=0, right_sum=0;
    Vertex *search_vertex = searchVertex(left);
    splay(search_vertex);
    if(root->key >= left){
      left_sum = root->sum - root->key;
    }
    else{
      left_sum = root->sum;
    }
    if(root->right)
      left_sum -= root->right->sum;
    
    //printf("root key = %lld, root sum = %lld\n", root->key, root->sum);
    search_vertex = searchVertex(right);
    splay(search_vertex);
   // printf("root key = %lld, root sum = %lld\n", root->key, root->sum);
    if(root->key > right){
      right_sum = root->sum - root->key;
    }
    else{
      right_sum = root->sum;
    }
    if(root->right)
      right_sum -= root->right->sum;

    last_sum = right_sum-left_sum;
    //printf("left sum = %lld, right_sum = %lld\n", left_sum, right_sum);
    //printf("============\n");
    if(last_sum>=0){
      cout << last_sum << endl;
    }
    else{
      cout << last_sum << endl;
    }
  }

  void insert(long long int key){
    Vertex *search_vertex = searchVertex(key);
    
    if(!search_vertex){
      root = new Vertex(key, NULL);
      root -> sum = key;
    }
    else if (search_vertex->key != key){
      // Insert Elements
      Vertex *new_ver = new Vertex(key, search_vertex);
      new_ver->sum = key;
      if(search_vertex->key > key){
        search_vertex -> left = new_ver;
      }
      else{
        search_vertex -> right = new_ver;
      }
      while(search_vertex){
        search_vertex->sum += new_ver->sum;
        search_vertex = search_vertex->parent;
      }
      
      //Splay Tree
      splay(new_ver);
    }
    else{
      splay(search_vertex);
    }
    //cout << key << endl;
    return;
  }
  void splay(Vertex* node){
    if(!node)
      return;
    while(node -> parent){
      // zig
      Vertex *parent = node->parent;
      if(parent->left == node){
        rightRotation(node, parent);
      }
      //zag
      else{
        leftRotation(node, parent);
      }
    }
    root = node;

  }

  void rightRotation(Vertex* node, Vertex* parent){
    parent->sum -= node->sum;
    if(node->right){
      node->right->parent = parent;
      parent->sum += node->right->sum;
      node->sum -= node->right->sum;
    }
    node->sum += parent->sum;

    parent->left = node->right;

    if(!parent->parent){
      node->parent = NULL;
    }
    else if(parent == parent->parent->left){
      parent->parent->left = node;
      node->parent = parent->parent;
    }
    else{
      parent->parent->right = node;
      node->parent = parent->parent;
    }
    node->right = parent;
    parent->parent = node;


  }
  void leftRotation(Vertex* node, Vertex* parent){
    parent->sum -= node->sum;
    if(node->left){
      node->left->parent = parent;
      parent->sum += node->left->sum;
      node->sum -= node->left->sum;
    }
    node->sum += parent->sum;

    parent->right = node->left;

    if(!parent->parent){
      node->parent = NULL;
    }
    else if(parent == parent->parent->left){
      parent->parent->left = node;
      node->parent = parent->parent;
    }
    else{
      parent->parent->right = node;
      node->parent = parent->parent;
    }
    node->left = parent;
    parent->parent = node;

  }

  Vertex* searchVertex(long long int key){

    // No root
    if(!root){
      return NULL;
    }
    // Find element and return vertex pointer
    Vertex *now = root, *next = root;    
    while(next){
      if(next->key > key){
        now = next;
        next = next->left;        
      }
      else if (next->key < key){ 
        now = next;
        next = next->right;
      }
      else{
        return next;
      }
    }
    return now;
  }

  void search(long long int key){
    Vertex *search_vertex = searchVertex(key);
    if (!search_vertex || search_vertex->key != key)
      cout << "Not found" << endl;
    else
      cout << "Found" << endl;
    splay(search_vertex);
  }
};

int main(){
  int n;
  long long int num1, num2;
  cin >> n;
  char oper;
  SplayTree tree;

  for(int i=0 ; i<n ; i++){
    cin >> oper;
    switch(oper){
      //insert
      case '+':
        cin >> num1;
        tree.insert( (num1 + tree.getLastSum() ) % 1000000001);
        break;
      //find
      case '?':
        cin >> num1;
        tree.search( (num1+tree.getLastSum() ) % 1000000001);
        break;
      //delete
      case '-':
        cin >> num1;
        tree.remove( (num1 + tree.getLastSum() ) % 1000000001);
        break;
      //sum
      case 's':
        cin>> num1 >>num2;
        tree.sum((num1+tree.getLastSum()) % 1000000001, (num2+tree.getLastSum())% 1000000001 );
        break;

    }
    
  }

  return 0;
}