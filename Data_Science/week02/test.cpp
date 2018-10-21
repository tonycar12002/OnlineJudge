#include <time.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
class A{
public:
    static int a;
    int b;
    A(){a=5;b=3;}

    void out(){
        cout << &a << " " << &b << endl;
    }
};
int A::a = 5;
int main() {
    int c = 9;
    while(c--){
        cout << c <<endl;
    }

}
