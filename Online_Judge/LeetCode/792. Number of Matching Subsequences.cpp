/*
Author: Tony Hsiao
Date: 2019/05/07
Topic: 792. Number of Matching Subsequences
Speed: 168 ms 
Note: 
Solution1: Binarsy Search + Subsequences
https://www.acwing.com/solution/leetcode/content/624/

Solution2: Only use character table
https://www.cnblogs.com/grandyang/p/9201323.html
*/
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int ans = 0;
        vector<vector<pair<int, int>>> character_table(26);

        // create first element table
        for(int i=0;i<words.size();i++){
            character_table[words[i][0] - 'a'].emplace_back(i, 0); //word location, charcter index
        }
        
        for(int i=0;i<S.size();i++){
           vector<pair<int, int>> char_row = character_table[S[i] - 'a'];
           character_table[S[i] - 'a'].clear();
           for(int j = 0 ; j<char_row.size() ; j++){
                if( words[char_row[j].first].size() == char_row[j].second + 1) // check subsequence
                    ans++;
                else
                    character_table[words[char_row[j].first][char_row[j].second + 1] - 'a'].\
                        emplace_back(char_row[j].first, char_row[j].second + 1);
           }
        }
        return ans;
    }
};