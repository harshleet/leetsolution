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
        if(lp!=NULL && rp!=NULL){
            return root;
        }

        if(root==p && (lp!=NULL && rp!=NULL)){
            return root;
        }
        if(root==q && (lp!=NULL && rp!=NULL)){
            return root;
        }
        if(root==p ||root==q){
            return root;
        }
        if(lp!=NULL){
            return lp;
        }
        if(rp!=NULL){
            return rp;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }
};