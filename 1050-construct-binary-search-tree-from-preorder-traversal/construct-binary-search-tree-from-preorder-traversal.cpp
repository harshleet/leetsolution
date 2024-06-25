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
    TreeNode* helper(int st,int en,vector<int>&preorder){
        if(st>en){
            return NULL;
        }

        TreeNode* root=new TreeNode(preorder[st]);
        int np=st+1;
        while(np<=en && preorder[st]>preorder[np]){
            np++;
        }
        // cout<<st<<" "<<np<<endl;
        root->left=helper(st+1,np-1,preorder);
        root->right=helper(np,en,preorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(0,preorder.size()-1,preorder);
    }
};