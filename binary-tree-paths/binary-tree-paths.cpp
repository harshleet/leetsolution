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
   void to_arrow(vector<string>&an,vector<vector<int>>&ans){
       
       for(int i=0;i<ans.size();i++){
           string s="";
           for(int j=0;j<ans[i].size()-1;j++){
               s+=to_string(ans[i][j]);
               s+="->";
           }
           s+=to_string(ans[i].back());
           an.push_back(s);
       }
   }
   void helper(vector<int>ds,vector<vector<int>>&ans,TreeNode* root){
       if(root==NULL){
           return;
       }
       if(root->left==NULL && root->right==NULL){
           ds.push_back(root->val);
           ans.push_back(ds);
           return;
       }
       ds.push_back(root->val);
       helper(ds,ans,root->left);
       helper(ds,ans,root->right);
       ds.pop_back();
       return;
   }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int>ds;
        vector<vector<int>>ans;
        helper(ds,ans,root);
        vector<string>an;
        to_arrow(an,ans);
        return an;
    }
};