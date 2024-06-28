class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>ind(n,0);
        for(auto it:roads){
            ind[it[0]]++;
            ind[it[1]]++;
        }
        sort(ind.begin(),ind.end());
        long long l=1,ans=0;
        for(int i=0;i<ind.size();i++){
            ans=ans+(ind[i]*l);
            l++;
        }
        return ans;
    }
};