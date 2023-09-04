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
void helper(string ds,vector<string>&ans,TreeNode* root){
       if(root==NULL){
           return;
       }
      ds+=('a'+root->val);
       if(root->left==NULL && root->right==NULL && !ds.empty()){
           cout<<ds<<" ";
           ans.push_back(ds);
       }
   
       helper(ds,ans,root->left);
       helper(ds,ans,root->right); 
       ds.pop_back();
      
   }
    string smallestFromLeaf(TreeNode* root) {
        string ds="";
        vector<string>ans;
        helper(ds,ans,root);
      
        for(int i=0;i<ans.size();i++){
            
            reverse(ans[i].begin(),ans[i].end());
        }
          sort(ans.begin(),ans.end());
        return ans[0];
    }
};