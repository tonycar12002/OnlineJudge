/*
Author: Tony Hsiao
Date: 2019/05/01 
Topic: 17. Letter Combinations of a Phone Number
Speed: 4 ms
Note: DFS
*/
class Solution {
private:
    vector<string> ans;
    map<int, string> phone_table;
public:
    void DFS(string digits, string current, int index){
        
        if(current.size() == digits.size())
            ans.push_back(current);
        else{
            int number = digits[index] - 48;
            for(int i=0 ; i < phone_table[number].size() ; i++)
                DFS(digits, current + phone_table[number][i], index + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return ans;
        char cur='a';
        for(int i=2;i<=9;i++){
            string letter="";
            for(int j=0;j<3;j++)
                letter += cur++;
            if (i==9 || i ==7)
                letter += cur++;
            phone_table[i] = letter;
        }

        string current;
        DFS(digits, current, 0);
        
        return ans;
    }
};