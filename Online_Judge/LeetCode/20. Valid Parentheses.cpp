/*
Author: Tony Hsiao
Date: 2019/04/24
Topic: 20. Valid Parentheses
Note: 括號匹配
*/
class Solution {
public:
    int parentheses_to_int(char ch){
        if(ch == '(')
            return 0;
        else if(ch == ')')
            return 1;
        else if(ch=='{')
            return 2;
        else if(ch == '}')
            return 3;
        else if(ch=='[')
            return 4;
        else
            return 5;
    }
    bool isValid(string s) {
        stack<int> stk;
        for(int i=0;i<s.size();i++){
            int ch = parentheses_to_int(s[i]);
            if(ch%2==1){
                //cout << ch/2 <<" " << stk.top()/2 << endl;
                if(stk.size() !=0 && stk.top()/2 == ch/2)
                    stk.pop();
                else
                    return false;
            }
            else
                stk.push(ch);
        }
        if(stk.size()==0)
            return true;
        else
            return false;
    }
};
