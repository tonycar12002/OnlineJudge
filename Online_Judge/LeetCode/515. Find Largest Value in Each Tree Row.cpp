/*
Author: Tony Hsiao
Date: 2019/05/06
Topic: 515. Find Largest Value in Each Tree Row
Note: Linked-List
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int>ans;
    map<int, int>record_map;
public:
    int max(int x, int y){
        return (x>y) ? x : y;
    }
    void TraverseTree(TreeNode* root, int level){
        if(root){
            if(map.find(level) == map.end()) //not found
                record[level] = root->val;
            else
                record[level] = max(record[level], root->val);
            TraverseTree(root->left, level+1);
            TraverseTree(root->right, level+1);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        TraverseTree(root, 0);
        for(map<int, int>::iterator iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
            ans.push_back(iter->second);
        return ans;
    }
};