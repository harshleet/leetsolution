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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* cur=root;

        vector<int>ans;
        map<TreeNode*,int>mp;
        while(cur!=NULL){
            if(mp.find(cur)==mp.end()){
                mp[cur]=1;
                ans.push_back(cur->val);
            }
             
            if(cur->left==NULL){
               
                cur=cur->right;
            }else{
                TreeNode* rightmost=cur->left;

                while(rightmost->right!=NULL){
                    rightmost=rightmost->right;
                }
                rightmost->right=cur;
                TreeNode* temp=cur;
                cur=cur->left;
                temp->left=NULL;
            }
        }
        return ans;
    }
};