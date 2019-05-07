/*
Author: Tony Hsiao
Date: 2019/04/24
Topic: 70. Climbing Stairs
Speed: 4 ms
Note: fibonacci series
*/
class Solution {
public:
    int climbStairs(int n) {
        int first = 1, second = 1;
        int ans = 0;
        if(n == 1)
            return 1;
        while(--n){
            ans = first + second;
            first = second;
            second = ans;
        }
        return ans;
    }
};