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
    void helper(TreeNode* root,vector<int>&cov,int &maxi){
        if(root==NULL){
            return;
        }
        for(int i=0;i<cov.size();i++){
            maxi=max(maxi,abs(cov[i]-root->val));
        }
        cov.push_back(root->val);
        helper(root->left,cov,maxi);
        helper(root->right,cov,maxi);
        cov.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int>cov;
        int maxi=0;
        helper(root,cov,maxi);
        return maxi;
    }
};