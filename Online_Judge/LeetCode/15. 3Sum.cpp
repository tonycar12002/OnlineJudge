/*
Author: Tony Hsiao
Date: 2019/04/25
Topic: 15. 3Sum
Speed: 104 ms
Note: Simply three sums problem to two sums problem
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); 
        
        for(int i = 0 ; i < nums.size() ; i++){
             // change three sum to two sum problem
            if(nums[i] > 0)
                break;
            else if(i > 0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            int left = i + 1, right = nums.size()-1;         
            while(left < right){
                if((right < nums.size()-1 && nums[right] == nums[right+1] ) || nums[left] + nums[right] > target)
                    right --;
                else if((left > i+1 && nums[left] == nums[left-1]) || nums[left] + nums[right] < target)
                    left ++;
                else if(nums[left] + nums[right] == target){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    right --;
                    left ++;
                }
            }
        }
        return ans;
    }
};