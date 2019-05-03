/*
Author: Tony Hsiao
Date: 2019/05/01
Topic: 49. Group Anagrams
Note: Hash Table to find the anagrams
*/
class Solution {
private:
    vector<vector<string>> ans;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int counter = 0;
        int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 
            43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        
        map<long long, int>value_to_int;
        for(int i = 0 ; i < strs.size() ; i++){
            string cur = strs[i];
            long long  hash_value = 1;
            for(int j = 0 ; j < cur.size() ; j++) // calculate hash values
                hash_value = hash_value * primes[(cur[j]-97)] % 2147483647;
            if(value_to_int.find(hash_value) == value_to_int.end()){
                value_to_int[hash_value] = counter;
                counter += 1;
                vector<string> tmp;
                ans.push_back(tmp);
            }
            ans[value_to_int[hash_value]].push_back(cur);
            
        }
        return ans;
    }
};