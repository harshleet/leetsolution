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
    void to_graph(TreeNode* root,map<TreeNode*,vector<TreeNode*>>&adj,set<TreeNode*>&leaf){
        if(root==NULL){
            return;
        }

        if(root->right==NULL && root->left==NULL){
            leaf.insert(root);
        }
        
        if(root->left!=NULL){
            adj[root].push_back(root->left);
             adj[root->left].push_back(root);
        }
        if(root->right!=NULL){
            adj[root].push_back(root->right);
             adj[root->right].push_back(root);
        }
        to_graph(root->left,adj,leaf);
        to_graph(root->right,adj,leaf);
    }

    int helper(TreeNode* node, map<TreeNode*,vector<TreeNode*>>&adj,set<TreeNode*>&leaf,int distance){
        
        queue<pair<TreeNode*,int>>q;
        map<TreeNode*,int>vis;
        int c=0;

        q.push({node,0});
        vis[node]=1;
        while(!q.empty()){
            TreeNode* n=q.front().first;
            int dis=q.front().second;
            q.pop();

            if(dis>distance){
                break;
            }
            if(leaf.find(n)!=leaf.end() && dis!=0){
                // cout<<node->val<<" "<<n->val<<endl;
                c++;
            }
            for(auto it:adj[n]){
                if(vis.find(it)==vis.end()){
                    vis[it]=1;
                    q.push({it,dis+1});
                }
            }

        }
        return c;
    }
    int countPairs(TreeNode* root, int distance) {
        map<TreeNode*,vector<TreeNode*>>adj;
        set<TreeNode*>leaf;
        to_graph(root,adj,leaf);
        cout<<leaf.size()<<endl;
        int c=0;
        for(auto it:leaf){
            c+=helper(it,adj,leaf,distance);
        }
        return c/2;
    }
};