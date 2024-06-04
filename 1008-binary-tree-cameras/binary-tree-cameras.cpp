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
    int dfs(TreeNode* root,int &ans){
        if(root==NULL){
            return 1;
        }
        int lc=dfs(root->left,ans);
        int rc=dfs(root->right,ans);

        if(lc==0 || rc==0){
            ans++;
            return 2;
        }else if(lc==2 || rc==2){
            return 1;
        }
        return 0;
       
    }
    int minCameraCover(TreeNode* root) {
        int ans=0;
       int val=dfs(root,ans);
       if(val==0){
        ans++;
       }
       return ans;
    }
};