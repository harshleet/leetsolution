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
    void helper(TreeNode* root,map<int,vector<int>>&m,int lvl){
        if(root==NULL){
            return;
        }
        m[lvl].push_back(root->val);
        helper(root->left,m,lvl+1);
        helper(root->right,m,lvl+1);

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int,vector<int>>m;
        vector<vector<int>>ans;
        helper(root,m,0);
        for(auto it:m){
           ans.push_back(it.second);
        }
        return ans;
    }
};