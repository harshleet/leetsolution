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
    pair<int,int> helper(TreeNode* root,int& ans){
        if(root==NULL){
            return {-1,-1};
        }
        if(root->left==NULL && root->right==NULL){
            return {root->val,root->val};
        }
        int mini=root->val,maxi=root->val;
        if(root->left!=NULL){
            pair<int,int>p=helper(root->left,ans);
            mini=min({mini,p.first,p.second});
            maxi=max({maxi,p.first,p.second});
        }

        if(root->right!=NULL){
            pair<int,int>p=helper(root->right,ans);
            mini=min({mini,p.first,p.second});
            maxi=max({maxi,p.first,p.second});
        }
        ans=max(ans,abs(mini-root->val));
        ans=max(ans,abs(maxi-root->val));
        return {maxi,mini};
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxi=0;
        helper(root,maxi);
        return maxi;
    }
};