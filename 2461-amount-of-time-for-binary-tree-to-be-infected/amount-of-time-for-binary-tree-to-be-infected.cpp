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
 void create_adj(map<int, vector<int>>& adj, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if (root->right != NULL) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        create_adj(adj, root->left);
        create_adj(adj, root->right);
    }
    void dfs(int root, map<int, vector<int>>& adj, int k,
             map<int, int>& vis,int &ans) {
           vis[root]=1;
           ans=max(ans,k);
        
        for (auto it : adj[root]) {
            if (vis.find(it) == vis.end()) {
                dfs(it, adj, k +1, vis, ans);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        map<int, vector<int>> adj;
        create_adj(adj, root);
        map<int, int> vis;
        int ans=0;
        dfs(start, adj, 0, vis, ans);
        return ans;
    }
};