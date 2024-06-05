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
    int helper(TreeNode* root,map<TreeNode*,int>&dp){
        if(root==NULL){
            return 0;
        }
        if(dp.find(root)!=dp.end()){
            return dp[root];
        }
        int nt=helper(root->left,dp)+helper(root->right,dp);
        int t=root->val;
        if(root->left!=NULL){
            t+=helper(root->left->left,dp)+helper(root->left->right,dp);
        }
        if(root->right!=NULL){
            t+=helper(root->right->left,dp)+helper(root->right->right,dp);
        }
        return dp[root]=max(nt,t);
    }
    int rob(TreeNode* root) {
        map<TreeNode*,int>dp;
        return helper(root,dp);
    }
};