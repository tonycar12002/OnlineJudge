/*
Author: Tony Hsiao
Date: 2019/05/07
Topic: 650. 2 Keys Keyboard
Speed: 4 ms, 8.2 MB  
Note:
*/
class Solution {
public:
    int min(int x, int y){
        return (x>y) ? y : x ;
    }
    int minSteps(int n) {
        if(n == 1)
            return 0;
        int ans = INT_MAX;
        for(int i = n-1 ; i>=1 ; i--){
            if(n%i == 0)
                ans = min(ans, minSteps(i)+n/i);
        }
        return ans;
    }
};