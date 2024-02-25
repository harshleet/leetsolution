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
    bool search(TreeNode* root,TreeNode* tar){
        if(root==NULL){
            return false;
        }
        bool a=false;
        if(root->val==tar->val){
          a=true;
        }
        return a|search(root->left,tar)|search(root->right,tar);
    }
    TreeNode* ans=NULL;
   TreeNode* helper(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL){
            return NULL; 
        }
        if(root->val==p->val){
            return p;
        }
          if(root->val==q->val){
            return q;
        }
        TreeNode* ls=helper(root->left,p,q);
        TreeNode* rs=helper(root->right,p,q);
        if(ls==NULL &&  rs==NULL){
            return NULL;
        }
        else if(ls!=NULL && rs!=NULL){
            return root;
        }
        else if(ls!=NULL && rs==NULL){
            return ls;
        }
        else{
            return rs;
        }
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return helper(root,p,q);
       
    }
};