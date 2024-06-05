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
    int count(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+count(root->left)+count(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return 0;
        }
        int l=count(root->left);
        int r=count(root->right);
        cout<<l<<" "<<r<<endl;
        if(k==l+1){
            return root->val;
        }
        if(k<=l){
           return kthSmallest(root->left,k);
        } return kthSmallest(root->right,k-l-1);
    }
};