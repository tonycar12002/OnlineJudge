#include <iostream>
#include <vector>
#include <string>
using namespace std;
int operation(int a, int b, char op){
    if(op=='+')
        return a+b;
    else if(op=='-')
        return a-b;
    else if(op=='*')
        return a*b;
    else;
}
int getMaximum(string formula){
    int len = formula.length();
    int numberOfNum = (len+1)/2;
    int minArray[numberOfNum][numberOfNum]={0};
    int maxArray[numberOfNum][numberOfNum]={0};


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
            int min_v=10000, max_v=-100, j = i+s;
            for(int k=i;k<j;k++){
                int a, b, c, d;
                a = operation(minArray[i][k], minArray[k + 1][j], formula[2 * k + 1] );
                b = operation(minArray[i][k], maxArray[k + 1][j], formula[2 * k + 1] );
                c = operation(maxArray[i][k], minArray[k + 1][j], formula[2 * k + 1] );
                d = operation(maxArray[i][k], maxArray[k + 1][j], formula[2 * k + 1] );
                min_v = min(min_v, a);
                min_v = min(min_v, b);
                min_v = min(min_v, c);
                min_v = min(min_v, d);
                max_v = max(max_v, a);
                max_v = max(max_v, b);
                max_v = max(max_v, c);
                max_v = max(max_v, d);
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