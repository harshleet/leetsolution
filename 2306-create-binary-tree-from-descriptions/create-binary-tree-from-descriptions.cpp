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
    TreeNode* dfs(int val,map<int,vector<pair<int,int>>>&adj){
        TreeNode* node=new TreeNode(val);

        for(auto it:adj[val]){
            if(it.second==0){
                node->right=dfs(it.first,adj);
            }else if(it.second==1){
                node->left=dfs(it.first,adj);
            }
        }
        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n=descriptions.size()+1;
        map<int,vector<pair<int,int>>>adj;
        map<int,int>in;
        for(auto it:descriptions){
            adj[it[0]].push_back({it[1],it[2]});
            in[it[1]]++;
        }

        for(auto it:adj){
            if(in[it.first]==0){
                
                return dfs(it.first,adj);
            }
        }
        return NULL;

    }
};