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
int height(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return (1+max(height(root->left),height(root->right)));
}
    bool isBalanced(TreeNode* root) {
        //not differ more than 1
        if(root==NULL){
            return true;
        }
        bool a=true;
        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(lh-rh)>1){
            a=false;
        }
        return (a& isBalanced(root->left)& isBalanced(root->right));
        
    }
};