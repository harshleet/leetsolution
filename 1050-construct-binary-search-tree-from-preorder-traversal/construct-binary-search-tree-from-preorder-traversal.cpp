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
    TreeNode* create(int st,int end,vector<int>&preorder){
        if(st>end){
            return NULL;
        }
        
        int k=st+1;
        TreeNode* root=new TreeNode(preorder[st]);
        for(int i=st+1;i<=end;i++){
            if(preorder[i]<preorder[st]){
                k++;
            }else{
                break;
            }
        }
      
        root->left=create(st+1,k-1,preorder);
        root->right=create(k,end,preorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return create(0,preorder.size()-1,preorder);
    }
};