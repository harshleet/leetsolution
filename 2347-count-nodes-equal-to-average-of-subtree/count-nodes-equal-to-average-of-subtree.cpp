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
    pair<int,int> helper(TreeNode* root,int& a){
        if(root==NULL){
            return {0,0};
        }
        auto temp1=helper(root->left,a);
        auto temp2=helper(root->right,a);
        int left=temp1.first;
        int right=temp2.first;

        int sum=root->val+left+right;
        int nodes=1+temp1.second+temp2.second;
       int avg=sum/nodes;
       if(avg==root->val){
           a++;
       }
        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        //no bfs use; the dfs
        int a=0;
        helper(root,a);
        return a;
    }
};