/*
Author: Tony Hsiao
Date: 2019/04/30
Topic: 66. Plus One
Speed: 4 ms
Note: 最基礎陣列
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;

        for(int i=digits.size()-1 ;i>=0;i--){
            digits[i] += carry;
            carry =  digits[i] / 10;
            digits[i] %= 10;
        }
        if(carry !=0 )
            digits.insert(digits.begin(), 1);
        return digits;
    }
};