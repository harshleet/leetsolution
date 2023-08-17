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
    int helper(TreeNode* root,map<TreeNode*,int>&m){
        if(root==NULL){
            return 0;
        }
        if(m.find(root)!=m.end()){
            return m[root];
        }
        int pick=root->val;
        if(root->right!=NULL){
           pick+=helper(root->right->left,m)+helper(root->right->right,m);
        }
        if(root->left!=NULL){
            
            pick+=helper(root->left->left,m)+helper(root->left->right,m);
        }
        int npick=helper(root->right,m)+helper(root->left,m);
        return  m[root]=max(npick,pick);
    }
    int rob(TreeNode* root) {
        map<TreeNode*,int>m;
        return helper(root,m);
    }
};