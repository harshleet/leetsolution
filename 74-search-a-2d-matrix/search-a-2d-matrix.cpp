class Solution {
public:
    bool binarySearch(int row,vector<vector<int>>& matrix,int target){
        int low=0,high=matrix[row].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[row][mid]==target ){
                return true;
            }
            else if(matrix[row][mid]>target){
                high=mid-1;
            }else {
                low=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high=matrix.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid][0]<=target && matrix[mid].back()>=target){
                bool a=binarySearch(mid,matrix,target);
                return a;
            }
            else if(matrix[mid][0]>target){
                high=mid-1;
            }else if(matrix[mid].back()<target){
                low=mid+1;
            }
        }
        return false;
    }
};