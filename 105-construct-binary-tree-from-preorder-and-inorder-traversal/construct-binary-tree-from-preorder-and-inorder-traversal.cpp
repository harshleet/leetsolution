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
    TreeNode* construct(int ps,int pe,int is,int ie,vector<int>& preorder, vector<int>& inorder){
        if(ps>pe || is>ie){
            return NULL;
        }
        int root_val=preorder[ps];
        TreeNode* root=new TreeNode(root_val);
        int pi=0;
        while(inorder[pi]!=root_val){
            pi++;
        }
        // cout<<ps+1<<" "<<ps+pi-is<<" "<<is<<" "<<pi-1<<endl;
        root->left=construct(ps+1,ps+pi-is,is,pi-1,preorder,inorder);
        root->right=construct(ps+pi-is+1,pe,pi+1,ie,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construct(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder);
    }
};