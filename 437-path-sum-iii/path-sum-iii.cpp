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
    // int dfs(TreeNode* root,long long int tar){
    //     if(root==NULL){
    //         return 0;
    //     }
    //     if(tar-root->val==0){
    //         return 1+dfs(root->left,tar-root->val)+dfs(root->right,tar-root->val);
    //     }
    //     int l=dfs(root->left,tar-root->val);
    //     int r=dfs(root->right,tar-root->val);
    //     return l+r;
    // }
    int helper(TreeNode* root,long long sum,long long int tar,map<long long int,long long int>&mp){
        if(root==NULL){
            return 0;
        }
        int ans=0;
        sum+=root->val;
        ans+=mp[sum-tar];
        mp[sum]++;
        int l=helper(root->left,sum,tar,mp);
        int r=helper(root->right,sum,tar,mp);
        mp[sum]--;
        sum-=root->val;
        return l+r+ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        map<long long int,long long int>mp;
        mp[0]=1;
        return helper(root,0,targetSum,mp);
    }
};