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
    TreeNode* helper(TreeNode* root,int key,set<TreeNode*>&st){
        if(root==NULL){
            return NULL;
        }
        TreeNode* l=helper(root->left,key,st);
        TreeNode* r=helper(root->right,key,st);

        if(root->val==key){
            if(root->left!=NULL){
               st.insert(root->left);
            }
            if(root->right!=NULL){
               st.insert(root->right);
            }
            if(st.find(root)!=st.end()){
                st.erase(root);
            }
            return NULL;
        }
            root->left=l;
            root->right=r;
        
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==NULL){
            return {};
        }
        ;
        set<TreeNode*>st;
        st.insert(root);
        for(int i=0;i<to_delete.size();i++){
            for(auto it:st){
               helper(it,to_delete[i],st);
              
            }
        }
        vector<TreeNode*>ans(st.begin(),st.end());
        return ans;
    }
};