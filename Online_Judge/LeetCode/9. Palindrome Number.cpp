/*
Author: Tony Hsiao
Date: 2018/05/29
Topic: 9. Palindrome Number
Note: 數字是否迴文
*/
class Solution {
public:
    bool isPalindrome(int x) {
    	int inverse_num = 0;
  		int x_copy = x;
  		int remain ;
        if(x<0)
        	return false;
        else if(x==0)
        	return true;
        else{
        	while(x_copy>0){
        		remain = x_copy%10;
        		x_copy /= 10;
        		inverse_num = inverse_num*10+remain;
        	}
        }
        if(inverse_num == x){
        	return true;
        }
        else
        	return false;
    }
};