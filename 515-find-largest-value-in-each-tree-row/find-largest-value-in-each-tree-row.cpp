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
    void bfs(TreeNode* root,map<int,vector<int>>&m,int lvl){
        if(root==NULL){
             return;
         }
        
            m[lvl].push_back(root->val);
       
         bfs(root->left,m,lvl+1);
         bfs(root->right,m,lvl+1);
    }
    vector<int> largestValues(TreeNode* root) {
        map<int,vector<int>>m;
        bfs(root,m,0);
        vector<int>v;
        for(auto it:m){
            v.push_back(*max_element(it.second.begin(), it.second.end()));
        }
        return v;
    }
};