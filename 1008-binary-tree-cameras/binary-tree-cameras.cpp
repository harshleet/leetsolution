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
    int helper(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }
        int v1=helper(root->left,ans);
        int v2=helper(root->right,ans);

        if(v1==0 && v2==0){
            return 1;
        }
        if(v1==1|| v2==1){
            ans++;
            return 2;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=0;
        int val=helper(root,ans);
        if(val==1){
            ans++;
        }
        return ans;
    }
};