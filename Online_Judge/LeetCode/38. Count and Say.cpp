/*
Author: Tony Hsiao
Date: 2019/04/30
Topic: 38. Count and Say
Note: 找到鄰近陣列加起來最大的值
*/
class Solution {
public:
    int max(int a, int b){
        return (a>b) ? a : b;
    }
    int maxSubArray(vector<int>& nums) {
        int max_sum = 0;
        const int size = nums.size();
        int max_sum_array[size]={0};

        max_sum_array[0] = nums[0];
        max_sum = nums[0];
        for(int i=1;i<nums.size();i++){
            max_sum_array[i] = max(max_sum_array[i-1] + nums[i], nums[i]);
            max_sum = max(max_sum, max_sum_array[i]);
        }
        return max_sum;
    }
};