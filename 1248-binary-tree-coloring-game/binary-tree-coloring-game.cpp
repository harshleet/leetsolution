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
   
    int countNode(TreeNode* root){
         if(root==NULL){
            return 0;
        }
        return 1+countNode(root->right)+countNode(root->left);
        
    }
  
    TreeNode* finder(TreeNode* root, int x) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == x) {
            return root;
        }

        // Update the recursive calls to properly return the found node
        TreeNode* leftResult = finder(root->left, x);
        if (leftResult != nullptr) {
            return leftResult;
        }

        return finder(root->right, x);
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
     
        if(root->val==x){
            if(countNode(root->left)==countNode(root->right)){
                return false;
            }
            return true;
        }
       TreeNode* r=finder(root,x);
      
        int lc=countNode(r->left);
        int rc=countNode(r->right);
        
        int pc=n-lc-rc-1;
         if(pc>lc+rc ||lc>pc+rc || rc>lc+pc){
             return true;
         }
         return false;

    
    }
};