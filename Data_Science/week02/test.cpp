#include <time.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class A{
public:
    vector<A*>child;

};
int main(){
    A a, b;
    a.child.push_back(&b);
    a.child.push_back(&b);
    a.child.push_back(&b);
    a.child.push_back(&b);
    a.child.push_back(&b);
    a.child.push_back(&b);
    a.child.push_back(&b);
    b.child.push_back(&a);
    b.child.push_back(&a);
    b.child.push_back(&a);
    b.child.push_back(&a);
    b.child.push_back(&a);
    b.child.push_back(&a);
    b.child.push_back(&a);
    b.child.push_back(&a);
    //cout << sizeof(A) << endl;
    //cout << a.child.capacity()  << endl;
    //cout << sizeof(A) * a.child.capacity() << endl;;

    vector<int>test;
    cout << sizeof(test) <<endl;

    queue<int> que;
    cout << sizeof(que) << endl;
    return 0;
}