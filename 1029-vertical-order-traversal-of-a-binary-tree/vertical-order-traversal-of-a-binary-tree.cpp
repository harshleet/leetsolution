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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        int lvl=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front().first;
                int wid=q.front().second;
                q.pop();
                mp[wid][lvl].insert(node->val);

                if(node->left!=NULL){
                    q.push({node->left,wid-1});
                }
                if(node->right!=NULL){
                    q.push({node->right,wid+1});
                }
            }
            lvl++;
        }
        vector<vector<int>>ans;
        for(auto it:mp){
            vector<int>temp;
            for(auto itr:it.second){
                vector<int>a(itr.second.begin(),itr.second.end());
                temp.insert(temp.end(),a.begin(),a.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};