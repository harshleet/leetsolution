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
    void helper(TreeNode* root,vector<int>&in){
        if(root==NULL){
            return;
        }
        helper(root->left,in);
        in.push_back(root->val);
        helper(root->right,in);
    }
    TreeNode* create(vector<int>&in,int st,int end){
        if(st>end){
            return NULL;
        }
        int ind=(st+end)/2;
        TreeNode* root=new TreeNode(in[ind]);
        root->left=create(in,st,ind-1);
        root->right=create(in,ind+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        helper(root,in);
        return create(in,0,in.size()-1);
    }
};