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
    bool helper(TreeNode* root,long long mini,long long maxi){
        if(root==NULL){
            return true;
        }
        if(root->val>=mini || root->val<=maxi){
            return false;
        }
        return helper(root->left,root->val,maxi)&& helper(root->right,mini,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,LLONG_MAX,LLONG_MIN);
    }
};