#include <time.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <iomanip>
using namespace std;
int main() {
    int c = 0.147449* 1000000;
    if( c % 100 >= 45)
        c = c /100 + 1;
    else
        c = c/100;
    double d = (double)c/10000;
    cout << fixed <<  setprecision(4) << ":"  << d << endl;


}
