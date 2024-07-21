class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>adj(k+1);
        vector<int>ind(k+1);
        for(int i=0;i<rowConditions.size();i++){
            adj[rowConditions[i][0]].push_back(rowConditions[i][1]);
            ind[rowConditions[i][1]]++;
        }

        queue<int>q;
        vector<int>row(k+1,-1);
        int r=0;
        for(int i= 1;i<=k;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();

            row[node]=r;
            r++;

            for(auto it:adj[node]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }

        vector<vector<int>>adj1(k+1);
        vector<int>ind1(k+1);
        for(int i=0;i<colConditions.size();i++){
            adj1[colConditions[i][0]].push_back(colConditions[i][1]);
            ind1[colConditions[i][1]]++;
        }

        queue<int>q1;
        vector<int>col(k+1,-1);
        int c=0;
        for(int i=1;i<=k;i++){
            if(ind1[i]==0){
                q1.push(i);
            }
        }

        while(!q1.empty()){
            int node=q1.front();
            q1.pop();

            col[node]=c;
            c++;

            for(auto it:adj1[node]){
                ind1[it]--;
                if(ind1[it]==0){
                    q1.push(it);
                }
            }
        }

        vector<vector<int>>ans(k,vector<int>(k));
        for(int i=1;i<=k;i++){
            
            if(row[i]==-1 || col[i]==-1){
                return {};
            }
            ans[row[i]][col[i]]=i;
        }
        return ans;
       
    }
};