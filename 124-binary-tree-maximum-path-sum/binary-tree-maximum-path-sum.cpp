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
    int maxi=INT_MIN;
    int helper(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int l=helper(root->left);
        int r=helper(root->right);

        maxi=max({maxi,root->val,root->val+l,root->val+r,root->val+l+r});

        return max({root->val+l,root->val+r,root->val});
    }
    int maxPathSum(TreeNode* root) {
         helper(root);
         return maxi;
    }
};