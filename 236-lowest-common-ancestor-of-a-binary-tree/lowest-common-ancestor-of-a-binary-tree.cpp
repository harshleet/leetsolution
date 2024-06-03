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
        //SO from both root we have some non-NULL vAL SO WE RETURN ROOT
        if(lp!=NULL && rp!=NULL){
            return root;
        }
        //if root is itself p and e are getting some non NULL valur feom one child hence we return root
        if(root==p && (lp!=NULL && rp!=NULL)){
            return root;
        }
         //if root is itself q and e are getting some non NULL valur feom one child hence we return root
        if(root==q && (lp!=NULL && rp!=NULL)){
            return root;
        }
        //no last chaeck no lp and rp has something bothe are  NULL but root is either p or q than we return it
        if(root==p ||root==q){
            return root;
        }
        //no root do not havenyhing we return their childrens
        if(lp!=NULL){
            return lp;
        }
        if(rp!=NULL){
            return rp;
        }
        //if nohing in all of them we return the NULL
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }
};