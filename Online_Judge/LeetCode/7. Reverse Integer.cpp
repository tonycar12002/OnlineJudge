/*
Author: Tony Hsiao
Date: 2018/05/29
Topic: 7. Reverse Integer
Speed: 30 ms
Note: 數字反轉
*/
class Solution {
public:
    int reverse(int x) {
        int remain;
        long long int ans = 0;
        while(x != 0){
            remain = x % 10;
            x = x/10;
            ans = ans*10 + remain;
            if (ans > 2147483648 || ans <= -2147483648){
                ans = 0;
                break;
            }
        }

        return ans;
    }
};