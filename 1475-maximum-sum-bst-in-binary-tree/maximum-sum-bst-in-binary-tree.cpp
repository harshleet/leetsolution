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
   vector<int> helper(TreeNode* root){
        if(root==NULL){
            return {0,INT_MAX,INT_MIN};
        }
        vector<int>t1=helper(root->left);
        vector<int>t2=helper(root->right);
        
        if(t1.empty() || t2.empty()){
            return {};
        }
        int sum=0;
        int mn=root->val,mx=root->val;
        if(!t1.empty() && t1[2]>=root->val){
            // cout<<
            return {};
        }else if(!t1.empty()){
            mn=min(mn,t1[1]);
            sum+=t1[0];
        }

        if(!t2.empty()&& t2[1]<=root->val){
            return {};
        }else if(!t2.empty()){
            mx=max(mx,t2[2]);
            sum+=t2[0];
        }
        maxi=max(maxi,sum+root->val);
        return {sum+root->val,mn,mx};
   }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxi;
    }
};