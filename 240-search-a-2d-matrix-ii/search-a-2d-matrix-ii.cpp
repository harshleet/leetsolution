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
        
        for(int i=0;i<matrix.size();i++){
            if(search(i,matrix,target)){
                return true;
            }
        }
        return false;
    }
};