/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  void helper(TreeNode* root,map<int,vector<int>>&adj){
      if(root==NULL){
          return;
      }
      if(root->left!=NULL){
           adj[root->val].push_back(root->left->val);
           adj[root->left->val].push_back(root->val);
      }
      if(root->right!=NULL){
           adj[root->val].push_back(root->right->val);
           adj[root->right->val].push_back(root->val);
      }
      helper(root->left,adj);
      helper(root->right,adj);
  }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //make th graph
        if(root==NULL){
            return {};
        }
        map<int,vector<int>>adj;
        helper(root,adj);
        vector<int>ans;
        queue<pair<int,int>>q;
        q.push({target->val,0});
        map<int,int>vis;
        while(!q.empty()){
            int node=q.front().first;
            int dis=q.front().second;
             q.pop();
            vis[node]=1;
            if(dis==k){
                ans.push_back(node);
            }
           
            for(auto it:adj[node]){
                if(vis.find(it)==vis.end()){
                      q.push({it,dis+1});
                }
               
            }
        }
        return ans;
    }
};