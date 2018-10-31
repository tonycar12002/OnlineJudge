#include <iostream>
#include <vector>
using namespace std;
int findEqualSum(vector<int>num, int total){
    int counts = 0, size = num.size();
    if(size==1 || total%3!=0)
        return 0;
    else{
        int DP_table[500][500], base = total/3;
        for(int i=0;i<=num.size();i++)
            DP_table[i][0] = 0;
        for(int j=0;j<=total;j++)
            DP_table[0][j] = 0;

        for(int i=1;i<=num.size();i++){
            for(int j=1;j<=total;j++){
                DP_table[i][j]=DP_table[i-1][j];
                if (num[i-1]<=j){     
                    DP_table[i][j] = max(DP_table[i][j], DP_table[i-1][j-num[i-1]] + num[i-1]);
                }
            }
        }
        for(int j=1;j<=total;j++){
            if(DP_table[num.size()][j] == base*(counts+1))
                counts++;
        }
        if(counts == 3)
            return 1;
        else    
            return 0;
    }

}
int main()
{
    int n, tmp, total = 0;
    cin>>n;
    vector<int>num;
    for(int i=0;i<n;i++){
        cin>>tmp;
        total+=tmp;
        num.push_back(tmp);
    }
    cout  << findEqualSum(num, total) << endl;
    return 0;
}