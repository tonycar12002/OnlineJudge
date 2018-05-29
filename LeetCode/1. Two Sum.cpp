/*
Author: Tony Hsiao
Date: 2018/05/29
Topic: 1. Two Sum
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        unordered_map<int,int> numMap;
        for(int i =0;i<numbers.size();i++)
            numMap[numbers[i]] = i;
        for(int i =0;i<numbers.size();i++)
        {
            int minus = target - numbers[i];
            auto t = numMap.find(minus);
            //make sure don't use same elements
            if(t!=numMap.end() && i!=t->second)
            {
                ans.push_back(i);
                ans.push_back(t->second);
                return ans;
            }            
        }
    }    
};