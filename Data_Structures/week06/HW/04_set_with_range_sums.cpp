#include <iostream>
#include <vector>

using namespace std;
class Vertex{
public:
  int key;
  Vertex* left;
  Vertex* right;
  Vertex* parent;

  Vertex():left(NULL), right(NULL), parent(NULL){}
};
class SplayTree{
private:
  Vertex* root;
  long long int last_sum ;

public:
  SplayTree():root(NULL), last_sum(0){}
  ~SplayTree();

  long long int getLastSum(){return last_sum;}
  void insert(long long int key){

  }

  void remove(long long int key){


  }

  void sumRange(long long int left, long long int right){

  }

  bool search(long long int key){

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
        tree.insert(num1 + tree.getLastSum());
        break;
      //find
      case '?':
        cin >> num1;
        tree.search(num1+tree.getLastSum());
        break;
      //delete
      case '-':
        cin >> num1;
        tree.remove(num1 + tree.getLastSum() );
        break;
      //sum
      case 's':
        cin>> num1 >>num2;
        break;

    }
    
  }

  return 0;
}