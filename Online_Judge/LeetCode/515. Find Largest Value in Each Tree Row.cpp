/*
Author: Tony Hsiao
Date: 2019/05/02
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
    map<int, int>
public:
    int max(int x, int y){
        return (x>y) ? x : y;
    }
    void TraverseTree(TreeNode* root, int level){
        if(root){
            record[level] = max(record[level], root->val);
            TraverseTree(root->left, level+1);
            TraverseTree(root->right, level+1);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        TraverseTree(root, 0);
        for(int i=0;i<1000;i++)
            if(record[i]!=0)
                ans.push_back(record[i]);
        return ans;
    }
};