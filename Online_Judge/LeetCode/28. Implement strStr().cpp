/*
Author: Tony Hsiao
Date: 2019/04/25
Topic: 28. Implement strStr()
Note: Brute Force
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 0;
        if(needle.size() == 0)
            return 0;
        for(int i=0;i<haystack.size();i++){
            for(j=0;j<needle.size();j++){
                if(haystack[i+j] != needle[j])
                    break;
            }
            if(j==needle.size())
                return i;
        }
        return -1;
    }
};
