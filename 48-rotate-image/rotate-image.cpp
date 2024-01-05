class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left=0,right=matrix[0].size()-1,top=0,bottom=matrix.size()-1;
         vector<int>ans;
         vector<int>temp;
         while(left<=right && top<=bottom){
             
             for(int i=left;i<=right;i++){
                  temp.push_back(matrix[top][i]);
             }
             top++;
           
            for(int i=top;i<=bottom;i++){
                 temp.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                    for(int i=right;i>=left;i--){
                        temp.push_back(matrix[bottom][i]);
                    }
                    bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    temp.push_back(matrix[i][left]);
                }
                left++;
            }
         }
         left=0,right=matrix[0].size()-1,top=0,bottom=matrix.size()-1;
         int a=0;
         while(left<=right && top<=bottom){
            for(int i=top;i<=bottom;i++){
                 matrix[i][right]=temp[a];
                 a++;
            }
            right--;
            if(top<=bottom){
                    for(int i=right;i>=left;i--){
                        matrix[bottom][i]=temp[a];
                         a++;
                    }
                    bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    matrix[i][left]=temp[a];
                     a++;
                }
                left++;
            }
             for(int i=left;i<=right;i++){
                  matrix[top][i]=temp[a];
                 a++;
             }
             top++;
         }
    }
};