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
    void dfs(TreeNode* root,vector<int>&par){
        if(root==NULL){
            return;
        }
        for(int i=0;i<par.size();i++){
            maxi=max(abs(root->val-par[i]),maxi);
        }
        par.push_back(root->val);
        dfs(root->left,par);
        dfs(root->right,par);
        par.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        vector<int>par;
        dfs(root,par);
        return maxi;
    }
};