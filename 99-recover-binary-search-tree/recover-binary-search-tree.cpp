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
    TreeNode* pre=new TreeNode(-1e9);
    vector<pair<TreeNode*,TreeNode*>>v;
    void helper(TreeNode* root){
        if(root==NULL){
            return;
        }
        helper(root->left);
        if(pre->val!=-1e9 && root->val<pre->val){
            v.push_back({pre,root});
        }
        pre=root;
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        // cout<<v.size()<<endl;
        if(v.size()==2){
            swap(v[0].first->val,v[1].second->val);
        }
        if(v.size()==1){
            swap(v[0].first->val,v[0].second->val);
        }
    }
};