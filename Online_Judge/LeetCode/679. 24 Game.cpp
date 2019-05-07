/*
Author: Tony Hsiao
Date: 2019/05/07
Topic: 679. 24 Game
Speed: 36ms, 15.7MB
Note: 嘗試所有答案
*/
class Solution {
private:
    double min_error = 0.001;
    bool is_find = false;
    double target = 24;
public:
    void Exhaustive(vector<double>nums){
        if(is_find) 
            return void();
        
        if(nums.size()==1 && abs(nums[0] - target) < min_error)
            is_find = true;
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                double p = nums[i], q = nums[j];
                vector<double>comb{p + q,  p - q, p * q, q - p};
                
                if( abs(p - min_error) > 0 )
                    comb.push_back(q/p);
                if( abs(q - min_error) > 0 )
                    comb.push_back(p/q);                 
                nums.erase(nums.begin() + i);
                nums.erase(nums.begin() + j - 1);
                
                for(int k = 0 ; k < comb.size() ; k++){ 
                    nums.push_back(comb[k]);
                    Exhaustive(nums);
                    nums.pop_back();
                }
                nums.insert(nums.begin() + i, p);
                nums.insert(nums.begin() + j, q);
               
            }
        }
        
    }
    bool judgePoint24(vector<int>& nums) {
        vector<double>copy(nums.begin(), nums.end());
        Exhaustive(copy);
        return is_find;
    }

};