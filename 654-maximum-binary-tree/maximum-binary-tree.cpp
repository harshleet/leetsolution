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
TreeNode* maker(vector<int>& nums,int si,int ei){
        if(si>=nums.size()|| si>ei ||ei<0){
            return NULL;
        }
        int maxind=si;
        int maxi=0;
        for(int i=si;i<=ei;i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                maxind=i;
            }
        }
        
        cout<<maxind<<endl;
        TreeNode* root= new TreeNode(nums[maxind]);
        root->left=maker(nums,si,maxind-1);
        root->right=maker(nums,maxind+1,ei);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return maker(nums,0,nums.size()-1);
    }
};