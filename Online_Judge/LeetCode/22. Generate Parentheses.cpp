/*
Author: Tony Hsiao
Date: 2019/04/24
Topic: 22. Generate Parentheses
Note: DFS
*/
class Solution {
public:
    void ParenthesesGenerate(vector<string> &ans, string current, int left, int right, int n){
        if(left + right == n * 2){
            ans.push_back(current);
            return void();
        }
        else if(left == n)
            ParenthesesGenerate(ans, current + ")", left, right+1, n);
        else if(left>right){
            ParenthesesGenerate(ans, current + ")", left, right+1, n);
            ParenthesesGenerate(ans, current + "(", left+1, right, n);
        }
        else
            ParenthesesGenerate(ans, current + "(", left+1, right, n);

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        ParenthesesGenerate(ans, "", 0, 0, n);
        return ans;
    }
};