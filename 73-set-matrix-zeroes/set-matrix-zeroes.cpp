class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>r(matrix[0].size(),0);
        map<int,int>m;
        map<int,int>m1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                 if(matrix[i][j]==0){
                    m1[i]=1;
                     m[j]=1;
                 }
            }
        }
        for(auto it:m1){
                matrix[it.first]=r;
           
        }
        for(auto it:m){
            for(int i=0;i<matrix.size();i++){
                matrix[i][it.first]=0;
            }
        }
        
    }
};