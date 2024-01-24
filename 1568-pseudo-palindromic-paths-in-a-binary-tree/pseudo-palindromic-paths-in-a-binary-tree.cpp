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
   int ans=0;
   int cnt=0;
   bool check(map<int,int>&ds){
    
       int an=0;
       for(auto it:ds){
           if(it.second%2==1){
               an++;
           }
       }
       return an<=1;
   }
    void helper(map<int,int>&ds,TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ds[root->val]++;
            cout<<ds.size()<<" ";
            if(check(ds)){
                ans++;
            }
            ds[root->val]--;
            if(ds[root->val]==0){
                ds.erase(root->val);
            }
            
        }
        ds[root->val]++;
        helper(ds,root->left);
        helper(ds,root->right);
        ds[root->val]--;
        if(ds[root->val]==0){
            ds.erase(root->val);
        }

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int>ds;
        if(root==NULL){
            return 0;
        }
        helper(ds,root);
        return ans;
    }
};