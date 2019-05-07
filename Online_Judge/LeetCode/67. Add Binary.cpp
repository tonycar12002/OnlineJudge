/*
Author: Tony Hsiao
Date: 2019/05/07
Topic: 67. Add Binary
Speed: 8 ms
Note:
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int size_1 = a.size()-1;
        int size_2 = b.size()-1;
        int tmp;
        string ans="";

        int carry = 0;
        while(size_1 !=-1 && size_2!=-1){
            tmp = a[size_1--] + b[size_2--] + carry - '0' - '0';
            carry = tmp/2;
            tmp %= 2;
            ans = to_string(tmp) + ans;
        }
        if (size_1 == -1){
            a = b;
            size_1 = size_2;
        }
        while(size_1 != -1){
            tmp = a[size_1--] + carry - '0';
            carry = tmp/2;
            tmp %= 2;
            ans = to_string(tmp) + ans;
        }

        if(carry == 1) ans = to_string(1) + ans;
        return ans;
    }
};