/*
Author: Tony Hsiao
Date: 2019/05/07
Topic: 542. 01 Matrix
Speed: 196 ms, 21.1MB
Note: Dynamic Programming, 來回各一次全部更新完成
*/
class Solution {
private:
public:
    int min(int x, int y){
        return (x>y) ? y : x ;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), INT_MAX-1));

        for(int y = 0 ; y < matrix.size() ; y++){
            for(int x = 0 ; x < matrix[y].size() ; x++){
                if(matrix[y][x]){
                    if(y > 0)
                        ans[y][x] = min(ans[y][x], ans[y-1][x] + 1);
                    if(x > 0)
                        ans[y][x] = min(ans[y][x], ans[y][x-1] + 1);
                }
                else
                    ans[y][x] = 0;
            }
        }
        for(int y = matrix.size()-1 ; y >=0  ; y--){
            for(int x = matrix[y].size() - 1  ; x >=0 ; x--){
                if(matrix[y][x]){
                    if(y != matrix.size()-1)
                        ans[y][x] = min(ans[y][x], ans[y+1][x] + 1);
                    if(x != matrix[y].size()-1)
                        ans[y][x] = min(ans[y][x], ans[y][x+1] + 1);
                }
                else
                    ans[y][x] = 0;
            }
        }
        return ans;
    }
};