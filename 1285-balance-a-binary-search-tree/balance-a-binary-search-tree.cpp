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
    void inorder(TreeNode* root,vector<int>&in){
        if(root==NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    TreeNode* construct(int st,int en,vector<int>&in){
        if(st>en){
            return NULL;
        }
        int mid=(st+en)/2;
        TreeNode* root=new TreeNode(in[mid]);
        root->left=construct(st,mid-1,in);
        root->right=construct(mid+1,en,in);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inorder(root,in);
        return construct(0,in.size()-1,in);
    }
};