/*
Author: Tony Hsiao
Date: 2019/04/30
Topic: 78. Subsets
Note: DFS
*/
class Solution {
private:
    vector<vector<int>> all_sets;
    int size;
public:
    void DFS(vector<int> nums, vector<int> current, int now_cursor){
        if(current.size() != size+1){
            all_sets.push_back(current);
            for(int i=now_cursor ; i<size ; i++){
                current.push_back(nums[i]);
                DFS(nums, current, i+1);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        size = nums.size();
        vector<int> current;
        DFS(nums, current, 0);
        return all_sets;
    }
};