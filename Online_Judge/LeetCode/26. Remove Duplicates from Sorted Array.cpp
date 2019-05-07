/*
Author: Tony Hsiao
Date: 2019/04/30
Topic: 26. Remove Duplicates from Sorted Array
Speed: 24 ms
Note:
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int record = 0 ;
        for(int i=0;i<nums.size();i++){
            if(i==0 || nums[i] != nums[i-1]){
                nums[record++] = nums[i];
            }
        }
        return record;
    }
};