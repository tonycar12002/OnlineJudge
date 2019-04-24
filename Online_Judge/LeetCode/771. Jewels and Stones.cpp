/*
Author: Tony Hsiao
Date: 2019/04/24
Topic: 771. Jewels and Stones
Note: 字串出現
*/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int record_table[127]={0};
        for(int i=0;i<J.size();i++)
            record_table[J[i]] = 1;
        int ans = 0;
        for(int i=0;i<S.size();i++){
            ans = (record_table[S[i]]==1) ? ans+1 : ans;
        }
        return ans;
    }
};