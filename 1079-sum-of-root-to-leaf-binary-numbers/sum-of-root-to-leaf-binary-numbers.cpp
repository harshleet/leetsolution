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
  
   int dfs(TreeNode* root,int sum){
        if(root==NULL){ 
            return 0;
        }
         sum = (sum << 1) | root->val;
       if(root->left==NULL && root->right==NULL ){
           return sum;
       }
        int lsum=dfs(root->left,sum);
        int rsum=dfs(root->right,sum);
       return lsum+rsum;
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
       int sum=0;
       int a= dfs(root,sum);
       
     
        return a;
    }
};