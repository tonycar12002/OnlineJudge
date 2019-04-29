/*
Author: Tony Hsiao
Date: 2019/04/25
Topic: 4. Median of Two Sorted Arrays
Note: 計算兩個已排序陣列的中位數
Not yet
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int mid = len/2;
        int left_x = 0, right_x = nums1.size()-1, left_y = 0, right_y = nums2.size()-1;
        bool is_odd = (len%2 == 1) ? true : false;

        while(left_x < right_x || left_y < right_y){
            int mid_x = (left_x + right_x)/2;
            int mid_y = (left_y + right_y)/2;
            if()
        }
        
    }
};
