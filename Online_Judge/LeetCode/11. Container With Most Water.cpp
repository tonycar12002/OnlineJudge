/*
Author: Tony Hsiao
Date: 2019/04/25
Topic: 11. Container With Most Water
Speed: 28 ms
Note: the max of [(x2-x1) * min(f(x1), f(x2)) ]
*/
class Solution {
public:
    int Area(vector<int>& hegiht, int l, int  r){
        int min_val = (hegiht[l] > hegiht[r]) ? hegiht[r] : hegiht[l];
        return min_val * (r-l);
    }
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int max_area = 0;
        while(left<right){
            max_area = max(max_area, Area(height, left, right));
            if(height[left] >= height[right])
                right -= 1;
            else
                left += 1;
        }
        return max_area;

    }
};