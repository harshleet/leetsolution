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
     
    bool helper(TreeNode* root,int sum,int target){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            return sum+root->val==target;
        }
        return helper(root->left,sum+root->val,target)|helper(root->right,sum+root->val,target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
      if(root==NULL){
          return false;
      }
      return helper(root,0,targetSum);
    }
};