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
   int height(TreeNode* root,unordered_map<int,int>&h){
        if(root==NULL){
            return 0;
        }
        int l=height(root->left,h);
        int r=height(root->right,h);
        h[root->val]=1+max(l,r);

        return 1+max(l,r);

   }
   

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int>ans;
        unordered_map<int,int>h;
        unordered_map<int,int>lev;
        int fh=height(root,h);
        // h[root->val]=fh;
        vector<int>lh1(1e5+1,INT_MIN);
        vector<int>lh2(1e5,INT_MIN);

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front().first;
                int lvl=q.front().second;
                q.pop();

                lev[node->val]=lvl;
                // cout<<node->val<<" "<<h[node->val]<<endl;
                if(lh1[lvl]<h[node->val]){
                    lh2[lvl]=lh1[lvl];
                    lh1[lvl]=h[node->val];

                }else if(lh2[lvl]<h[node->val]){
                    lh2[lvl]=h[node->val];
                }
                if(node->left!=NULL){
                    q.push({node->left,lvl+1});
                }
                if(node->right!=NULL){
                    q.push({node->right,lvl+1});
                }
            }
        }

        for(int i=0;i<queries.size();i++){
            if(queries[i]==root->val){
                ans.push_back(0);
                continue;
            }
            int lvl=lev[queries[i]];
            int height=h[queries[i]];
            int val=0;
            // cout<<queries[i]<<" "<<lh2[lvl]<<" "<<lh1[lvl]<<" "<<height<<" "<<lvl<<endl;
            if(lh1[lvl]==height && lh2[lvl]!=INT_MIN){ 
               val=max(lvl-1,lvl+lh2[lvl]-1);
            }else if(lh1[lvl]==height && lh2[lvl]==INT_MIN){
                val=lvl-1;
            }else if(lh1[lvl]!=height){
                val=max(lvl-1,lvl+lh1[lvl]-1);
            }
            ans.push_back(val);
        }
        return ans;
    }
};