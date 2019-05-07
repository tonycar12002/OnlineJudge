/*
Author: Tony Hsiao
Date: 2019/05/06
Topic: 392. Is Subsequence (64ms) 
Speed: 64 ms
Note:
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sub_seq = 0, seq = 0;
        while(sub_seq != s.size() && seq!=t.size()){
            (s[sub_seq] == t[seq]) ? (seq++, sub_seq++) : seq++;
        }
        return sub_seq == s.size() ? true : false;
    }
};