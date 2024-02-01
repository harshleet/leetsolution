class Solution {
public:
    int dfs(int ind,vector<vector<int>>& bombs,vector<int>&vis){
        vis[ind]=1;
        int r1=bombs[ind][2];
        int cnt=1;
        for(int i=0;i<bombs.size();i++){
            long long dis=pow(bombs[i][0]-bombs[ind][0],2)+pow(bombs[i][1]-bombs[ind][1],2);
            long long dis2= pow(r1,2);
            if(!vis[i] &&dis<=dis2){
               cnt+=dfs(i,bombs,vis);
            }
        }
  
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        
        int maxi=0;
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
                maxi=max(maxi,dfs(i,bombs,vis));
        }
        return maxi;
    }
};