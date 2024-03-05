class Solution {
public:
bool binarySearch(int row,vector<vector<int>>& matrix,int target){
        int low=0,high=matrix[row].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[row][mid]==target ){
                return true;
            }
            if(matrix[row][mid]>target){
                high=mid-1;
            }else {
                low=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]<=target && matrix[i].back()>=target){
                bool a=binarySearch(i,matrix,target);
                if(a==true){
                    return a;
                }
            }
        }
        
        return false;
    } 
};