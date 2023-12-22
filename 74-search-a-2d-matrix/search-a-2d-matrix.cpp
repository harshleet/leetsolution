class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i=0;i<matrix.size();i++){
            if(target<=matrix[i].back()){
                int low=0,high=matrix[i].size();
                while(low<=high){
                    int mid=(low+high)/2;
                    if(target<matrix[i][mid]){
                        high=mid-1;
                    }else if(target>matrix[i][mid]){
                        low=mid+1;
                    }else{
                        return true;
                    }
                }
            }
            
        }
        return false;
    }
};