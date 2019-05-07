/*
Author: Tony Hsiao
Date: 2019/05/01
Topic: 73. Set Matrix Zeroes
Speed: 48 ms
Note: Try to use constant space O(1) solution
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int size_x = matrix[0].size();
        int size_y = matrix.size();
        if(size_x == 0 || size_y == 0)
            return void();

        bool col_0 = false, row_0 = false;
        for(int y = 0 ; y<size_y; y++)
            col_0 |= (matrix[y][0] == 0);
        for(int x = 0 ; x<size_x ; x++)
            row_0 |= (matrix[0][x] == 0);

        for(int y = 1 ; y<size_y; y++){
            for(int x = 1 ; x<size_x ; x++){
                if(matrix[y][x] == 0){
                    matrix[y][0] = 0;
                    matrix[0][x] = 0;
                }
            }
        }
        for(int y = 1 ; y<size_y; y++)
            if(matrix[y][0] == 0)
                for(int x = 1 ; x<size_x ; x++)
                    matrix[y][x] = 0;
        for(int x = 1 ; x<size_x; x++)
            if(matrix[0][x] == 0)
                for(int y = 1 ; y<size_y; y++)
                    matrix[y][x] = 0;
        if(row_0)
            for(int x = 0 ; x<size_x ; x++)
                matrix[0][x] = 0;
        if(col_0)
            for(int y = 0 ; y<size_y; y++)
                matrix[y][0] = 0;
    }
};