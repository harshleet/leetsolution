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
    void helper(TreeNode* root,map<int,map<int,vector<int>>>&mp,int wi,int lvl){
        if(root==NULL){
            return;
        }
        mp[wi][lvl].push_back(root->val);

        helper(root->left,mp,wi-1,lvl+1);
        helper(root->right,mp,wi+1,lvl+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int,map<int,vector<int>>>mp;
        helper(root,mp,0,0);
        vector<vector<int>>ans;
        for(auto it:mp){
            vector<int>temp;
            for(auto itr:it.second){
                sort(itr.second.begin(),itr.second.end());
                for(int i=0;i<itr.second.size();i++){
                    temp.push_back(itr.second[i]);
                }
            }
            
            ans.push_back(temp);
        }
        return ans;
    }
};