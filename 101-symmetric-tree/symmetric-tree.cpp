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
    bool helper(TreeNode* le,TreeNode* ri){
        if(le==NULL && ri==NULL){
            return true;
        }
        if(le==NULL || ri==NULL){
            return false;
        }
        

        return (le->val==ri->val)&helper(le->left,ri->right)&helper(le->right,ri->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return helper(root->left,root->right);
    }
};