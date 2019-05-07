/*
Author: Tony Hsiao
Date: 2019/01/09
Topic: 14. Longest Common Prefix
Speed: 8 ms
Note: 純粹找所有字串中開頭字串重複的string
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string shortest;
        int min_=1000;
        for(int i=0;i<strs.size();i++){
            string tmp = strs[i];
            if(min_ >= tmp.size()){
                shortest = tmp;
                min_ = tmp.size();
            }
        }
        string ans="";   
        bool same = true;
        for(int i=0;i<min_;i++){
            for(int j=0;j<strs.size();j++){
                if(shortest[i] != strs[j][i]){
                    same = false;
                    break;
                }
            }
            if(same == false)
                break;
            ans += shortest[i];
        }
        
        return ans;
    }
};