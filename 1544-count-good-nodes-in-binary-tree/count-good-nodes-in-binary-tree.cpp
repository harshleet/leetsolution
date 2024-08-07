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
     int helper(TreeNode* root,int maxi){
        if(root==NULL){
            return 0;
        }
        int l=helper(root->left,max(maxi,root->val));
        int r=helper(root->right,max(maxi,root->val));
        int ans=l+r;
        if(root->val>=maxi){
            ans++;
        }
        return ans;
     }
    int goodNodes(TreeNode* root) {
        return helper(root,INT_MIN);
    }
};