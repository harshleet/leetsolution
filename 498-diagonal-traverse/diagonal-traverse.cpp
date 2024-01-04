class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>m;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                m[i+j].push_back(mat[i][j]);
            }
        }vector<int>ans;
        int x=0;
        for(auto it:m){
           if(x%2==0){
                reverse(it.second.begin(),it.second.end());
            }
            
            for(int i=0;i<it.second.size();i++){
                ans.push_back(it.second[i]);
            }
            x++;

        }
        return ans;
    }
};