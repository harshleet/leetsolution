/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root){
        if(root==NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        if(root->val==2){
            return helper(root->left)|helper(root->right);
        }else{
            return helper(root->right)& helper(root->left);
        }
    }
    bool evaluateTree(TreeNode* root) {
        return helper(root);
    }
};