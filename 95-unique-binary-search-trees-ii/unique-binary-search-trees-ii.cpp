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
 vector<TreeNode*> backtrack(int start,int end) {
        if(start>end){
            return {nullptr};
        }
      
      vector<TreeNode*>all;
        for(int i=start;i<=end;i++){
             vector<TreeNode*> left=backtrack(start,i-1);
             vector<TreeNode*> right=backtrack(i+1,end);
             for (TreeNode* l : left) {
                for (TreeNode* r : right) {
                    TreeNode* current_tree = new TreeNode(i);
                    current_tree->left = l;
                    current_tree->right = r;
                    all.push_back(current_tree);
                }
            }
        }
        return all;
    }
    vector<TreeNode*> generateTrees(int n) {
      
        return backtrack(1,n);
    }
};