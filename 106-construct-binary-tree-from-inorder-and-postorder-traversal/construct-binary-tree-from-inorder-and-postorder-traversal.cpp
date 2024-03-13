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
TreeNode* helper(int pst,int pend,int ist,int iend,vector<int>& postorder, vector<int>& inorder,map<int,int>&m){
       if(pst>pend || ist>iend ){
        return NULL;
       } 
       TreeNode* root=new TreeNode(postorder[pend]);
       int val=m[postorder[pend]];
       int noleft=val-ist;
       root->left=helper(pst,pst+noleft-1,ist,val-1,postorder,inorder,m);
       root->right=helper(pst+noleft,pend-1,val+1,iend,postorder,inorder,m);
       return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       map<int,int>m;
        for(int i=0;i<inorder.size();i++){
              m[inorder[i]]=i;
        }
        return helper(0,postorder.size()-1,0,inorder.size()-1,postorder,inorder,m);
    }
};