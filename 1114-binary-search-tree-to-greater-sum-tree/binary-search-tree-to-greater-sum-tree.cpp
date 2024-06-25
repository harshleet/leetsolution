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
    void filler(TreeNode* root,int sum){
        if(root==NULL){
            return;
        }
        cout<<root->val<<" "<<sum<<endl;
        root->val+=sum;
        filler(root->left,root->val);
        filler(root->right,0);
    }
    int helper(TreeNode* root,int& sum){
        if(root==NULL){
            return 0;
        }
        
        int rv=helper(root->right,sum);
        int v=root->val;
        root->val+=sum;
        sum+=v;
         int lv=helper(root->left,sum);
         return root->val;
      
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        helper(root,sum);
        // filler(root,0);
        return root;
    }
};