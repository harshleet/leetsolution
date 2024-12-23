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
    int swaps(vector<int>& temp){
        vector<pair<int,int>>ori;
        for(int i=0;i<temp.size();i++){
            ori.push_back({temp[i],i});
        }
        sort(ori.begin(),ori.end());
        vector<int>vis(temp.size());
        int ans=0;
        for(int i=0;i<temp.size();i++){
            if(vis[i]==1 || ori[i].second==i  ){
                continue;
            }
           

            int cycle_size = 0;
            int y = i;
            while (!vis[y]) {
                vis[y] = true;
                y = ori[y].second;
                cycle_size++;
            }

            if (cycle_size > 1) {
                ans += (cycle_size - 1);
            }
        }
        return ans;
       
    }
    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*>q;

        q.push(root);

        int ans=0;
        while(!q.empty()){
            int sz=q.size();

            vector<int>temp;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();

                temp.push_back(node->val);
                if(node->left!=NULL){
                    q.push(node->left);
                }

                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            int cnt=swaps(temp);
            ans+=cnt;
        }
        return ans;
    }
};