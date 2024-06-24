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
TreeNode* f=NULL;
TreeNode* s=NULL;
TreeNode* t=NULL;
TreeNode* pre=NULL;
   void helper(TreeNode* root){
        if(root==NULL){
            return ;
        }
        // cout<<root->val<<" "<<maxi<<" "<<mini<<endl;
        
        helper(root->left);
        if(pre!=NULL && root->val<pre->val){
            if(f==NULL){
                f=pre;
                s=root;
            }else{
                t=root;
            }
        }
        pre=root;
        helper(root->right);
        // return root;

   }
    void recoverTree(TreeNode* root) {
        helper(root);
        if(f!=NULL && s!=NULL && t==NULL){
            swap(f->val,s->val);
            // cout<<f->val<<" "<<s->val<<endl;
        }
        if(t!= NULL){
            swap(f->val,t->val);
        }
       
    }
};