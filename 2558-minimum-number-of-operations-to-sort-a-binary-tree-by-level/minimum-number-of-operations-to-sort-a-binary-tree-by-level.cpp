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
    int swap_count(vector<int>&v){
        int n=v.size();

        vector<bool>vis(n,false);
        vector<pair<int,int>>temp(n);
        for(int i=0;i<n;i++){
            // cout<<v[i]<<" ";
            temp[i]={v[i],i};
        }
        sort(temp.begin(),temp.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==temp[i].second || vis[i]==true){
                continue;
            }
            int j=i,clen=0;
            while(vis[j]==false){
                vis[j]=true;
                clen++;
                j=temp[j].second;
            }
            ans+=(clen-1);
        }
        // cout<<ans<<endl;
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
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
            int c=swap_count(temp);
            ans+=c;
        }
        return ans;
    }
};