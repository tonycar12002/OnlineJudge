/*
Author: Tony Hsiao
Date: 2019/04/30
Topic: 144. Binary Tree Preorder Traversal
Speed: 12 ms
Note: Preorder root->left->right
*/
class Solution {
private:
    vector<int> ans;
public:
    void PreOrder(TreeNode* root){
        if(root != NULL){
            ans.push_back(root->val);
            PreOrder(root->left);
            PreOrder(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        PreOrder(root);
        return ans;
    }
};