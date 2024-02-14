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
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* third=NULL;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
       
        if(second==NULL && prev->val>root->val){
            first=prev;
            second=root;
        }else if(second!=NULL && prev->val>root->val){
          third=root;
        }
        prev=root;
        inorder(root->right);

    }
    void recoverTree(TreeNode* root) {
        prev=new TreeNode(INT_MIN);
        inorder(root);
          if( third==NULL){
              cout<<first->val<<endl;
              swap(first->val,second->val);
          }else if( third!=NULL){
              cout<<first->val<<" "<<second->val<<" "<<third->val<<endl;
              swap(first->val,third->val);
          } 
    }
};