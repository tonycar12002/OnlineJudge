#include <iostream>
#include <vector>
using namespace std;
int calStringDist(string a, string b){
    int dist_table[101][101];
    for(int i=0;i<=a.length();i++)
        dist_table[i][0] = i;
    for(int i=0;i<=b.length();i++)
        dist_table[0][i] = i;        
    
    for(int i = 1; i<=a.length() ;i++){
        for(int j = 1; j<=b.length() ;j++){
            if(a[i-1] == b[j-1]){
                dist_table[i][j] = min(dist_table[i-1][j-1], dist_table[i-1][j]+1);
                dist_table[i][j] = min(dist_table[i][j], dist_table[i][j-1]+1);
            }
            else{
                dist_table[i][j] = min(dist_table[i-1][j]+1, dist_table[i-1][j-1]+1);
                dist_table[i][j] = min(dist_table[i][j], dist_table[i][j-1]+1);
            }
        }
    }
    //print DP table
    /*
    for(int i = 1; i<=a.length() ;i++){
        for(int j = 1; j<=b.length() ;j++){
            cout << dist_table[i][j] << " ";
        }   
        cout << endl;
    } 
    */
    return dist_table[a.length()][b.length()] ;
}
int main()
{
    string a, b;
    cin >> a >> b;

    cout << calStringDist(a, b) << endl;;

    return 0;
}