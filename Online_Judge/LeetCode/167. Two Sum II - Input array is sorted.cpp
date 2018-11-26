/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 167. Two Sum II - Input array is sorted
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int front = 0, back = numbers.size()-1;
        int sum;
        while(back>front){
            sum = numbers[back]+numbers[front];
            if(sum == target){
                ans.push_back(front+1);
                ans.push_back(back+1);
                return ans;
            }
            else if(sum>target){
                back--;
            }
            else
                front++;
        }
    }
};