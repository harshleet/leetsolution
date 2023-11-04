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
int maxi=0;
   void helper(TreeNode* root,int dir,int depth){
     if(root==NULL){
         return;
     }
  
        if(dir==1){
           helper(root->left,0,depth+1);
           helper(root->left,1,0);
        }
        else if(dir==0){
           helper(root->right,1,depth+1);
           helper(root->right,0,0);
        }
                maxi=max(maxi,depth); 
    
   }
    int longestZigZag(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
       helper(root,0,0);
        helper(root,1,0);
       return maxi;
    }
};