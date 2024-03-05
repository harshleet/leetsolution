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
        int i=0,j=matrix[0].size()-1;

        while(i<matrix.size() && j>=0){
            if(matrix[i][j]==target){
                return true;
            }else if(matrix[i][j]>target){
                j--;
            }else if(matrix[i][j]<target){
                i++;
            }

        }
        return false;
    } 
};