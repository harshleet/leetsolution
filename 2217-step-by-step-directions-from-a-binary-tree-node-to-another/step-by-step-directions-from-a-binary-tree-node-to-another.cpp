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
    
    string t;
     void dfs(TreeNode* node,int ds,string& ans){
        if(node==NULL){
            return;
        }
        if(node->val==ds){
            t=ans;
             return;
        }
        ans.push_back('L');
        dfs(node->left,ds,ans);
        ans.pop_back();
        ans.push_back('R');
        dfs(node->right,ds,ans);
        ans.pop_back();
        
     }

     TreeNode* lcoan(TreeNode* root, int p, int q){
        if(root==NULL){
            return NULL;
        }
        TreeNode* l=lcoan(root->left,p,q);
        TreeNode* r=lcoan(root->right,p,q);

        if(l!=NULL && r!=NULL ){
            return root;
        }else if((l!=NULL ||r!=NULL) && (root->val==p || root->val==q)){
            return root;
        }else if(root->val==p || root->val==q){
            return root;
        }else if(l!=NULL){
            return l;
        }else if(r!=NULL){
            return r;
        }
        return NULL;
     }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode* lca=lcoan(root,startValue,destValue);
        if(lca==NULL){
            return "";
        }
        string temp="";
        string ans="";
        dfs(lca,startValue,ans);
        string t2(t.size(),'U');
        temp+=t2;

        ans="";
        dfs(lca,destValue,ans);
        temp+=t;
        return temp;
    }
};