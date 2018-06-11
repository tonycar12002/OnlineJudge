#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
int maximumWeight(int capacity, vector<int>& item){
    int **DP_table = new int*[item.size()+1];

    for(int i=0;i<=item.size();i++){
        DP_table[i] = new int [capacity+1];
        DP_table[i][0] = 0;
    }
    for(int j=0;j<=capacity;j++)
        DP_table[0][j] = 0;

    for(int i=1;i<=item.size();i++){
        for(int j=1;j<=capacity;j++){
            DP_table[i][j]=DP_table[i-1][j];
            if (item[i-1]<=j){     
                DP_table[i][j] = max(DP_table[i][j], DP_table[i-1][j-item[i-1]] + item[i-1]);
            }

        }
    }
    /*
    for(int i=0;i<=item.size();i++){
        for(int j=0;j<=capacity;j++){
            cout << DP_table[i][j] << " ";
        }
        cout << endl;
    }    
    */
    return DP_table[item.size()][capacity];
}
int main()
{
    int tmp, W, n;
    cin>>W>>n;
    vector<int> item_weight;
    srand( time(NULL) );
    for(int i=0;i<n;i++){
        cin>> tmp;
        item_weight.push_back(tmp);
    }
    //cout << endl;
    cout << maximumWeight(W, item_weight) << endl;
    return 0;
}