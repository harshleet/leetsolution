class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>>adj(n);
        vector<int>ind(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            ind[edges[i][1]]++;
        }
        queue<int>q;
        vector<vector<int>>mp(n,vector<int>(26));
         int maxi=0;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                mp[i][colors[i]-'a']++;
                maxi=max(maxi,mp[i][colors[i]-'a']);
                q.push(i);
            }
        }
       
        
        while(!q.empty()){
            int node=q.front();
            q.pop();

            // maxi=max(maxi,*max_element(mp[node].begin(),mp[node].end()));
            for(auto it:adj[node]){
                for(int i=0;i<26;i++){
                    if(i==colors[it]-'a'){
                        mp[it][i]=max(mp[node][i]+1,mp[it][i]);
                    }else{
                        mp[it][i]=max(mp[node][i],mp[it][i]);
                    }
                    //  mp[it][i]=max(mp[node][i],mp[it][i]);
                }
               maxi=max(maxi,mp[it][colors[it]-'a']);
                 ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(ind[i]!=0){
                return -1;
            }
        }
        return maxi;
    }
};