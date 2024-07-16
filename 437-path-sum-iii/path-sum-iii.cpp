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
    int dfs(TreeNode* root,long long int tar){
        if(root==NULL){
            return 0;
        }
        if(tar-root->val==0){
            return 1+dfs(root->left,tar-root->val)+dfs(root->right,tar-root->val);
        }
        int l=dfs(root->left,tar-root->val);
        int r=dfs(root->right,tar-root->val);
        return l+r;
    }
    int helper(TreeNode* root,long long int tar){
        if(root==NULL){
            return 0;
        }
        int my=dfs(root,tar);
        int l=helper(root->left,tar);
        int r=helper(root->right,tar);
        return l+r+my;
    }
    int pathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum);
    }
};