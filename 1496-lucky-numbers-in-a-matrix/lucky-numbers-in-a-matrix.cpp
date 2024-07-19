class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
       
        vector<int>cm(matrix[0].size(),0);
        vector<int>rmi(matrix.size(),INT_MAX);
        
         int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              
                cm[j]=max(cm[j],matrix[i][j]);
                rmi[i]=min(rmi[i],matrix[i][j]);
               
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==rmi[i] && matrix[i][j]==cm[j]){
                    ans.push_back(matrix[i][j]);                }
            }
        }
        return ans;

    }
};