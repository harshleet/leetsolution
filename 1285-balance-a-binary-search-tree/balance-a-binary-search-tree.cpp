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
 TreeNode* maker(vector<int>& num,int si,int ei){
        if(si>=num.size()|| si>ei ||ei<0){
            return NULL;
        }
        int index=(si+ei)/2;
        TreeNode* root= new TreeNode(num[index]);
        root->left=maker(num,si,index-1);
        root->right=maker(num,index+1,ei);
        return root;
    }
    void dfs(TreeNode* root,vector<int>&val){
        if(root==NULL){
            return;
        }
        val.push_back(root->val);
        dfs(root->left,val);
        dfs(root->right,val);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>val;
        dfs(root,val);
        sort(val.begin(),val.end());
        int si=0,ei=val.size()-1;
         return maker(val,si,ei);
    }
};