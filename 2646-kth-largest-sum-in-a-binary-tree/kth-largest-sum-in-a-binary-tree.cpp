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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long>pq;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int sz=q.size();
            long long lsum=0;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                lsum+=node->val;

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }

            }
            pq.push(lsum);
        }
        for(int i=0;i<k-1 &&!pq.empty();i++){
            pq.pop();
        }
        if(pq.empty()){
            return -1;
        }
        return pq.top();
    }
};