#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>
using namespace std;
int64_t operation(int64_t a, int64_t b, char op){
    if(op=='+')
        return a+b;
    else if(op=='-')
        return a-b;
    else if(op=='*')
        return a*b;
    else;
}
int64_t mymin(int64_t a, int64_t b){
    if(a>=b)
        return b;
    else 
        return a;
}
int64_t mymax(int64_t a, int64_t b){
    if(a<b)
        return b;
    else 
        return a;
}
int64_t getMaximum(string formula){
    int len = formula.length();
    int numberOfNum = (len+1)/2;
    int64_t minArray[numberOfNum][numberOfNum]={0};
    int64_t maxArray[numberOfNum][numberOfNum]={0};


    for(int i=0;i<numberOfNum;i++){
        for(int j=0;j<numberOfNum;j++){
            minArray[i][j] = 100000;
            maxArray[i][j] = -100000;
        }
        minArray[i][i] = formula[i*2]-48;
        maxArray[i][i] = formula[i*2]-48;
    }
    for(int s=1;s<numberOfNum;s++){
        for(int i=0;i<numberOfNum-s;i++){
            int64_t min_v=10000, max_v=-100, j = i+s;
            for(int k=i;k<j;k++){
                int64_t a, b, c, d;
                a = operation(minArray[i][k], minArray[k + 1][j], formula[2 * k + 1] );
                b = operation(minArray[i][k], maxArray[k + 1][j], formula[2 * k + 1] );
                c = operation(maxArray[i][k], minArray[k + 1][j], formula[2 * k + 1] );
                d = operation(maxArray[i][k], maxArray[k + 1][j], formula[2 * k + 1] );
                min_v = mymin(min_v, a);
                min_v = mymin(min_v, b);
                min_v = mymin(min_v, c);
                min_v = mymin(min_v, d);
                max_v = mymax(max_v, a);
                max_v = mymax(max_v, b);
                max_v = mymax(max_v, c);
                max_v = mymax(max_v, d);
            }
            minArray[i][j] = min_v;
            maxArray[i][j] = max_v;
            
        }
    } 
    /*
    for(int i=0;i<numberOfNum;i++){
        for(int j=i;j<numberOfNum;j++){
            cout << maxArray[i][j] << " ";
        }
        cout << endl;
    }
    */
    return maxArray[0][numberOfNum-1];
}
int main()
{
    string input;
    cin>>input;
    cout << getMaximum(input) << endl;
    return 0;
}