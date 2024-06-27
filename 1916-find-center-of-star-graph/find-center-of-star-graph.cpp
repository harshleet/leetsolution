class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int>in(n+1,0);
        for(auto it:edges){
            in[it[0]]++;
            in[it[1]]++;
            if(in[it[0]]==n-1){
                return it[0];
            }
            if(in[it[1]]==n-1){
                return it[1];
            }
        }
        return -1;
    }
};