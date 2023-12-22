class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //two times binary search

        int low=0,high=matrix.size()-1;
        int ans=-1;
        while(low<=high){
                    int mid=(low+high)/2;
                    if(target<=matrix[mid].back() && target>=matrix[mid][0]){
                        ans=mid;
                        break;
                    }
                    else if(target>matrix[mid].back()){
                        low=mid+1;
                    }else if(target<matrix[mid][0]){
                        high=mid-1;
                    }
           }
          if(ans==-1){
              return false;
          }
           
                low=0,high=matrix[ans].size();
                while(low<=high){
                    int mid=(low+high)/2;
                    if(target<matrix[ans][mid]){
                        high=mid-1;
                    }else if(target>matrix[ans][mid]){
                        low=mid+1;
                    }else{
                        return true;
                    }
                }
           
            
        
        return false;
    }
};