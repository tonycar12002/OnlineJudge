/*
Author: Tony Hsiao
Date: 2019/04/25
Topic: 94. Binary Tree Inorder Traversal
Speed: 4 ms
Note: Inorder left->root->right
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
    vector<int> ans;
public:
    void InOrder(TreeNode* root){
        if(root != NULL){
            InOrder(root->left);
            ans.push_back(root->val);
            InOrder(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        InOrder(root);
        return ans;
    }
};