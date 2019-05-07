/*
Author: Tony Hsiao
Date: 2019/05/01
Topic: 39. Combination Sum
Speed: 16 ms
Note: DFS
*/
class Solution {
private:
    vector<vector<int>> ans;
public:
    void FindTarget(vector<int>& candidates, vector<int> cur_solution, int target, int index){
        if (target == 0)
            ans.push_back(cur_solution);
        for(int i = index ; i < candidates.size() ; i++){
            if(candidates[i] > target)
                break;
            cur_solution.push_back(candidates[i]);
            FindTarget(candidates, cur_solution, target - candidates[i], i);
            cur_solution.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        vector<int> cur;
        FindTarget(candidates, cur, target, 0);

        return ans;
    }
};