
#include <iostream>
#include <vector>
using namespace std;
int longestCommon(vector<int>A, vector<int>B, vector<int>C){
    /*
    ===========================================================================
        Be care for the initialization of array, don't use three for to initial
    ===========================================================================
    */
    int dist_table[101][101][101];
    for(int i = 0; i<=A.size() ;i++){
        for(int j = 0; j<=B.size() ;j++){
            for(int k = 0; k<=C.size() ;k++){
                if(i==0||j==0|k==0)
                    dist_table[i][j][k]  = 0;
                else if(A[i-1] == B[j-1] && B[j-1] == C[k-1]){
                    dist_table[i][j][k] = 1 + dist_table[i-1][j-1][k-1];
                }
                else{
                    dist_table[i][j][k] = max(dist_table[i-1][j][k], dist_table[i][j-1][k]);
                    dist_table[i][j][k] = max(dist_table[i][j][k], dist_table[i][j][k-1]);
                }
            }
        }
    }
    //print DP table
    /*
    for(int i = 0; i<=A.size() ;i++){
        for(int j = 0; j<=B.size() ;j++){
            cout << dist_table[i][j] << " ";
        }   
        cout << endl;
    } 
    */
    return dist_table[A.size()][B.size()][C.size()];
}

int main()
{
    int n ,m, l, tmp;
    vector<int>A, B, C;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        A.push_back(tmp);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>tmp;
        B.push_back(tmp);
    }   
    cin>>l;
    for(int i=0;i<l;i++){
        cin>>tmp;
        C.push_back(tmp);
    } 
    cout << longestCommon(A, B, C) << endl;;

    return 0;
}