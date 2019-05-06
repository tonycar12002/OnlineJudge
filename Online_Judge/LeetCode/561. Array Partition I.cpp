/*
Author: Tony Hsiao
Date: 2019/05/06
Topic: 561. Array Partition I
Note:
*/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i+=2)
            sum += nums[i];
        return sum;
    }
};