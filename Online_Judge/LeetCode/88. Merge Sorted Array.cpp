/*
Author: Tony Hsiao
Date: 2019/04/30
Topic: 88. Merge Sorted Array
Note: 
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int first = m-1, second = n-1;
        int cursor = first + second + 1;
        while(second >= 0){
            nums1[cursor--] = (first >=0 && nums1[first] > nums2[second]) ? nums1[first--] : nums2[second--];
        }
    }
};