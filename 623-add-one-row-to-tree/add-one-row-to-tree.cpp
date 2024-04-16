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
    void helper(TreeNode* root,int d,int val,int depth){
        if(root==NULL){
            return;
        }
        if(d==depth-1){
            TreeNode* temp=new TreeNode(val);
            TreeNode* temp2=new TreeNode(val);
            if(root->left!=NULL){
                TreeNode* t=root->left;
                root->left=temp;
                temp->left=t;
            }else{
                root->left=temp;
            }
            if(root->right!=NULL){
                TreeNode* t=root->right;
                root->right=temp2;
                temp2->right=t;
            }else{
                root->right=temp2;
            }
            return;
        }

        helper(root->left,d+1,val,depth);
        helper(root->right,d+1,val,depth);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL){
            return NULL;
        }
        if(depth==1){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        helper(root,1,val,depth);
        return root;
    }
};