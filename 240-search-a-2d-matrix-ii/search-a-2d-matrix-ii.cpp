class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top=0,bot=matrix.size()-1,low=0,high=matrix[0].size()-1;

        while(top<=bot && low<=high){
            if(matrix[top][high]==target || matrix[top][low]==target ||matrix[bot][low]==target || matrix[bot][high]==target){
                return true;
            }
            // cout<<low<<" "<<high<<" "<<top<<" "<<bot<<endl;
            if(matrix[top][high]>target){
                high--;
            }else if(matrix[bot][low]<target){
                low++;
            }else if(matrix[top][low]<target){
                top++;
            }else if(matrix[bot][high]>target){
                bot--;
            }
        }
        return false;
    }
};