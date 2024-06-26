class Solution {
public:
bool search(int row,vector<vector<int>>&matrix,int target){
        int l=0,h=matrix[0].size()-1;

        while(l<=h){
            int mid=(l+h)/2;
            if(target==matrix[row][mid]){
                return true;
            }else if(target<matrix[row][mid]){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //log(m*n)
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            if(matrix[i][j]<target){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};