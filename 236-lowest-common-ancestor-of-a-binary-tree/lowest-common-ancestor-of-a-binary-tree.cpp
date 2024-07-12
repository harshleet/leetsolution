/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return NULL;
        }
        TreeNode* lp=helper(root->left,p,q);
        TreeNode* rp=helper(root->right,p,q);

        if(root==p || root==q){
            return root;
        }
        if(lp==NULL && rp==NULL){
            return NULL;
        }else if(lp!=NULL && rp!=NULL){
            return root;
        }else if(lp!=NULL){
            return lp;
        }else if(rp!=NULL){
            return rp;
        }
        return NULL;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        return helper(root,p,q);
    }
};