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
    
    TreeNode* ino_suc(TreeNode* root){
       
        while(root->left!=NULL){
           
            root=root->left;
        }
         return root;
    }
    TreeNode* delete_node(TreeNode* root,int key){
        if(root==NULL){
            return NULL;
        }
        if(root->val>key){
          root->left=delete_node(root->left,key);
       }else if(root->val<key){
          root->right=delete_node(root->right,key);
       }else{
            if(root->left==NULL || root->right==NULL){
                    if(root->left==NULL){
                        return root->right;
                    }else if(root->right==NULL){

                        return root->left;
                    }
            }
            //inorder successor
            TreeNode* ins=ino_suc(root->right);
            root->val=ins->val;
            root->right=delete_node(root->right,ins->val);
       }
       
     
      return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        return delete_node(root,key);
      
    }
};