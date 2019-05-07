/*
Author: Tony Hsiao
Date: 2019/04/24
Topic: 3. Longest Substring Without Repeating Characters
Speed: 12 ms
Note: 利用array確定是否出現過該字元，從左到右跑一次即可完成，記得START更新要做判斷
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0, start = 0;
        int char_record[128];
        for(int i=0;i<128;i++)
            char_record[i] = -1;
        
        for(int i=0;i<s.size();i++){
            int ch = s[i];
            if(char_record[ch] == -1)
                char_record[ch] = i;
            else{
                if(start <= char_record[ch])
                    start = char_record[ch]+1;
                char_record[ch] = i;
            }
            max_length = max(max_length, i-start+1);
            //cout << s[i] << " " << char_record[ch] << " " << max_length << endl;
        }

        return max_length;
    }
};
