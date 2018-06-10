#include <iostream>
#include <vector>
using namespace std;
int longestCommon(vector<int>A, vector<int>B){
    int dist_table[101][101];
    for(int i=0;i<=A.size();i++)
        dist_table[i][0] = 0;
    for(int i=0;i<=B.size();i++)
        dist_table[0][i] = 0;   
    for(int i = 1; i<=A.size() ;i++){
        for(int j = 1; j<=B.size() ;j++){
            if(A[i-1] == B[j-1]){
                dist_table[i][j] = max(dist_table[i-1][j-1]+1, dist_table[i-1][j]);
                dist_table[i][j] = max(dist_table[i][j], dist_table[i][j-1]);
            }
            else{
                dist_table[i][j] = max(dist_table[i-1][j], dist_table[i-1][j-1]);
                dist_table[i][j] = max(dist_table[i][j], dist_table[i][j-1]);
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
    return dist_table[A.size()][B.size()];
}
int main()
{
    int n ,m, tmp;
    vector<int>A, B;
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

    cout << longestCommon(A, B) << endl;;

    return 0;
}