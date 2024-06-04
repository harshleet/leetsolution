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
    void create_adj(map<TreeNode*, vector<TreeNode*>>& adj, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
        }
        if (root->right != NULL) {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
        }
        create_adj(adj, root->left);
        create_adj(adj, root->right);
    }
    void dfs(TreeNode* root, map<TreeNode*, vector<TreeNode*>>& adj, int k,
             map<TreeNode*, int>& vis, vector<int>& ans) {
        if (root == NULL) {
            return ;
        }
           vis[root]=1;
        if(k<0){
            return;
        }
     
        if (k == 0) {
           
            ans.push_back(root->val);
        }
        
        for (auto it : adj[root]) {
            if (vis.find(it) == vis.end()) {
                dfs(it, adj, k - 1, vis, ans);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        map<TreeNode*, vector<TreeNode*>> adj;
        create_adj(adj, root);
        map<TreeNode*, int> vis;
        vector<int> ans;
        dfs(target, adj, k, vis, ans);
        return ans;
    }
};