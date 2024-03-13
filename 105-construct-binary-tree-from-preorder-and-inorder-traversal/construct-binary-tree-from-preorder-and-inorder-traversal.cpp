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
    TreeNode* helper(int pst,int pend,int ist,int iend,vector<int>& preorder, vector<int>& inorder,map<int,int>&m){
       if(pst>pend || ist>iend ){
        return NULL;
       } 
       TreeNode* root=new TreeNode(preorder[pst]);
       int val=m[preorder[pst]];
       int noleft=val-ist;
       root->left=helper(pst+1,pst+noleft,ist,val-1,preorder,inorder,m);
       root->right=helper(pst+noleft+1,pend,val+1,iend,preorder,inorder,m);
       return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
              m[inorder[i]]=i;
        }
        return helper(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder,m);
    }
};