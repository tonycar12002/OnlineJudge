/*
Author: Tony Hsiao
Date: 2019/04/24
Topic: 461. Hamming Distance
Speed: 4 ms
Note: 計算兩數字Hamming distance，使用XOR避免TLE，兩數字 直接用除法比較會TLE
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int xor_value = (x^y);
        while(xor_value != 0){
            ans = (xor_value%2==1) ? ans + 1 : ans;
            xor_value /= 2;
        }

        return ans;
    }
};
