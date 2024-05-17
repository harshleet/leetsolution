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

    void dfs(TreeNode* root,int target,TreeNode* par,int dir){
        if(root==NULL){
            return;
        }

        dfs(root->left,target,root,0);
        dfs(root->right,target,root,1);

        if(root->left==NULL && root->right==NULL && root->val==target){
            if(dir==0){
                par->left=NULL;
            }else{
                par->right=NULL;;
            }
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
           //easy
           TreeNode* par=new TreeNode(0);
           par->left=root;
           dfs(root,target,par,0);
           return par->left;
    }
};