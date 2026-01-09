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
    pair<TreeNode*,int> helper(int ll, int dep,TreeNode* root,int len){
        if(root==NULL){
            return make_pair(root,0);
        }
        if(root->left==NULL && root->right==NULL){
            if(len==dep){
                return {root,1};
            }
            return {root,0};
        }
        pair<TreeNode*, int>l=helper(ll,dep, root->left, len+1);
        pair<TreeNode*, int>r=helper(ll, dep, root->right,len+1);
        if(l.second==ll){
            return l;
        }else if(r.second==ll){
            return r;
        }else if(l.second+r.second==ll){
            return make_pair(root,ll);
        }else{
            return make_pair(root,l.second+r.second);
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // cslculate depth of this tree bfs
        if(root==NULL){
            return root;
        }

        queue<TreeNode*>q;
        int ll=0;
        int dep=1;
        int maxi=0;
        q.push(root);

        while(!q.empty()){
            ll=q.size();
            maxi=max(maxi,dep);
            for(int i=0;i<ll;i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            dep++;
        }


        // now nodes at deepst level return 1 else 0
        pair<TreeNode*, int>ans= helper(ll, maxi, root,1);
        return ans.first;

    }
};