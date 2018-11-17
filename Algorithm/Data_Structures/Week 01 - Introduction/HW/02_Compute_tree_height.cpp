#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Node
{
private:
	Node* parent;
	int key;
	std::vector<Node*> children;

public:
	Node(){
		parent = NULL;
	}
	void setParent(Node* theParent){
		this->parent = theParent;
		theParent->children.push_back(this);
	}
	void setKey(int theKey){
		key = theKey;
	}
	vector<Node*> getChild(){
		return children;
	}
};

int findTreeHeight(Node* node, int num, int layer){
	vector<Node*> child = node->getChild();
	int height = layer;
	for(int i=0;i<child.size();i++){
		int tmp =  findTreeHeight(child[i], num-child.size(), layer+1);
		height = max(height, tmp);
	}
	return height;
}
int main(int argc, char **argv){
	int n, parent_index;
	cin>>n;
	Node* root;
	std::vector<Node> nodeList;
	nodeList.resize(n);
	for(int child_index = 0 ; child_index<n ; child_index++){
		cin>>parent_index;
		if(parent_index>=0){
			nodeList[child_index].setParent( &nodeList[parent_index] );
			nodeList[child_index].setKey(child_index);
		}
		else
			root = &nodeList[child_index];
	}
	cout << findTreeHeight(root, n-1, 1) <<endl;
}