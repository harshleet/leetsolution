class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>adjr(k);
        vector<vector<int>>adjc(k);
        vector<int>inr(k,0);
        vector<int>inc(k,0);
        for(auto it:rowConditions){
            adjr[it[0]-1].push_back(it[1]-1);
            inr[it[1]-1]++;
        }
        for(auto it:colConditions){
            adjc[it[0]-1].push_back(it[1]-1);
            inc[it[1]-1]++;
        }
        vector<vector<int>>ans(k,vector<int>(k));
        queue<int>qr;
        queue<int>qc;

        for(int i=0;i<k;i++){
            if(inr[i]==0){
                qr.push(i);
            }
            if(inc[i]==0){
                qc.push(i);
            }
        }
        vector<int>row(k,-1);
        vector<int>col(k,-1);
        int r=0;
        while(!qr.empty()){
            int node=qr.front();
            qr.pop();
            row[node]=r;
            r++;
            for(auto it:adjr[node]){
                inr[it]--;
                if(inr[it]==0){
                    qr.push(it);
                }
            }
        }
         int c=0;
        while(!qc.empty()){
            int node=qc.front();
            qc.pop();
            col[node]=c;
            c++;
            for(auto it:adjc[node]){
                inc[it]--;
                if(inc[it]==0){
                    qc.push(it);
                }
            }
        }

        for(int i=0;i<k;i++){
            if(row[i]==-1 || col[i]==-1){
                return {};
            }
            ans[row[i]][col[i]]=i+1;
        }
        return ans;

    }
};