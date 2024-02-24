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
    void helper(TreeNode* root,vector<vector<int>>&ans){
        if(root==NULL){
            return;
        }
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty()){
           int n=q.size();
           vector<int>temp;
           for(int i=0;i<n;i++){
               TreeNode* node=q.front();
               q.pop();
               temp.push_back(node->val);
               if(node->left!=NULL){
                   q.push(node->left);
               }
               if(node->right!=NULL){
                   q.push(node->right);
               }
           }
           ans.push_back(temp);
       }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return{};
        }
        vector<vector<int>>ans;
        helper(root,ans);
        return ans;
    }
};