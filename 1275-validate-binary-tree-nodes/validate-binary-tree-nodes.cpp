class Solution {
public:
   bool dfs(int node,vector<int>&vis,vector<vector<int>>&adj){
        vis[node]=1;

        bool ans=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                ans&=dfs(it,vis,adj);
            }else{
                return false;
            }
        }
        return ans;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>>adj(n);
        vector<int>ind(n);
        vector<int>out(n);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
                ind[leftChild[i]]++;
                adj[i].push_back(leftChild[i]);
                out[i]++;
            }
            if(rightChild[i]!=-1){
                ind[rightChild[i]]++;
                adj[i].push_back(rightChild[i]);
                out[i]++;
            }
        }

        int cnt=0;
        int st=0;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                st=i;
                cnt++;
            }else if(ind[i]>1){
                return false;
            }else if(out[i]>2){
                return false;
            }
        }
        if(cnt>1 || cnt==0){
            return false;
        }
        vector<int>vis(n,0);
        bool ans=dfs(st,vis,adj);
        if(ans==false){
            return false;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                return false;
            }
        }
        return true;
    }
};