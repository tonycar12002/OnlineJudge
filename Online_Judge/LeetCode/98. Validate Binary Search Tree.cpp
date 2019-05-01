/*
Author: Tony Hsiao
Date: 2019/05/01
Topic: 98. Validate Binary Search Tree
Note: Check the tree is Binary Search Tree
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
public:
    bool isValid(TreeNode* root, long min, long max){
        if(!root)
            return true;
        if(root->val <= min || root->val >=max)
            return false;
        return isValid(root->left, min, root->val) && isValid(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};