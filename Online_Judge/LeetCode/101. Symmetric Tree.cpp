/*
Author: Tony Hsiao
Date: 2019/05/02
Topic: 101. Symmetric Tree
Speed: 8 ms
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
public:
    bool checkSymmetric(TreeNode* left, TreeNode* right){
        if(!left && !right)
            return true;
        else if(!left || !right || left->val!=right->val)
            return false;
        return checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left);;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return checkSymmetric(root->left, root->right);
    }
};