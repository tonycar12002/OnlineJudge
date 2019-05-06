/*
Author: Tony Hsiao
Date: 2019/05/06
Topic: 455. Assign Cookies
Note:
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int children = 0, cookies = 0; 
        while(children!=g.size() && cookies!=s.size()){
            (s[cookies] >= g[children]) ? (ans++, cookies++, children++) : cookies++;
        }
        return ans;
    }
};