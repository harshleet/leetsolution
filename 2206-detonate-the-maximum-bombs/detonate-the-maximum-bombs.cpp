class Solution {
public:
    void dfs(int ind,vector<vector<int>>& bombs,vector<int>&vis,int &cnt){
       
        vis[ind]=1;
        int r1=bombs[ind][2];
       cnt++;
        for(int i=0;i<bombs.size();i++){
          long long dis=pow(bombs[i][0]-bombs[ind][0],2)+pow(bombs[i][1]-bombs[ind][1],2);
           
            if(!vis[i] && i!=ind && dis<=pow(r1,2)){
               dfs(i,bombs,vis,cnt);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        
        int maxi=0;
        for(int i=0;i<n;i++){
                vector<int>vis(n,0);
                int cnt=0;
                dfs(i,bombs,vis,cnt);
                maxi=max(maxi,cnt);
        }
        return maxi;
    }
};