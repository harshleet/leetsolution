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
    int findBottomLeftValue(TreeNode* root) {
    
        map<int,int>m;
        queue<pair<TreeNode*,int>>q;

        q.push({root,0});

        while(!q.empty()){
            int si=q.size();
            for(int i=0;i<si;i++){
                
                TreeNode* node=q.front().first;
                int lvl=q.front().second;
                q.pop();

                if(m.find(lvl)==m.end()){
                    m[lvl]=node->val;
                }
                if(node->left!=NULL){
                    q.push({node->left,lvl+1});
                }
                if(node->right!=NULL){
                    q.push({node->right,lvl+1});
                }
            }
        }
        return prev(m.end())->second;
    }
};