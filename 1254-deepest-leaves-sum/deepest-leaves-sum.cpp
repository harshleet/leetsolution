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
 int ans=0;
   void helper(int& val,TreeNode* root,int lvl){
         if(root==NULL){
           return ;
       }
       cout<<lvl<<" ";
       if(val==lvl){
           ans+=root->val;
       }
       helper(val,root->left,lvl+1);
       helper(val,root->right,lvl+1);
   }
   int deep(TreeNode* root){
       if(root==NULL){
           return 0;
       }
       return 1+max(deep(root->left),deep(root->right));
   }
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int val=deep(root);
        // return val;
       
        helper(val,root,1);
        return ans;

    }
};