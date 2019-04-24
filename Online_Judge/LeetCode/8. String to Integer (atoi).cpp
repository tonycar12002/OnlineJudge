/*
Author: Tony Hsiao
Date: 2019/01/09
Topic: 8. String to Integer (atoi)
Note: 陣列中找數字
*/
class Solution {
public:
    int myAtoi(string str) {
        long long int value = 0;
        int ans;
        bool find_number = false;
        long long int inverse = 1;
        for(int i = 0 ; i<str.size() ; i++){   
            if(value*inverse > INT_MAX){
                value = 2147483647;
                break;
            }
            else if(value*inverse < INT_MIN){
                value = 2147483648;
                break;
            }
            else if(str[i]>='0' && str[i]<='9'){
                find_number = true;
                value = value * 10 + str[i] - '0';
            }
            else if(str[i] == ' ' && !find_number){
                continue;
            }
            else if(str[i] == '-' && !find_number){
                find_number = true;
                inverse = -1;
            }
            else if(str[i] == '+' && !find_number){
                find_number = true;
                inverse = 1;
            }
            else
                break;
        }
        if(value*inverse > INT_MAX){
            value = 2147483647;
        }
        else if(value*inverse < INT_MIN){
            value = 2147483648;
        }
        ans = value*inverse;
        return ans;
    }
};