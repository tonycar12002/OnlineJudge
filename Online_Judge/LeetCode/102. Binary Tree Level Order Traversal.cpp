/*
Author: Tony Hsiao
Date: 2019/05/06
Topic: 102. Binary Tree Level Order Traversal
Speed: 16 ms
Note: Queue
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
    vector<vector<int>> ans;
    int size = 0;
public:
    void DFS(TreeNode* root, int depth){
        if(root){
            if(depth >= size){
                size += 1;
                ans.push_back(vector<int>());
            }
            ans[depth].push_back(root->val);
            DFS(root->left, depth+1);
            DFS(root->right, depth+1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        DFS(root, 0);
        return ans;
    }
};