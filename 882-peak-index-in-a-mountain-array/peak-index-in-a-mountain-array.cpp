class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
         if(arr.size()==1){
            return 0;
        }
        int n=arr.size();
            if(arr[0]>arr[1]){
                return 0;
            }
             if(arr[n-1]>arr[n-2]){
                return n-1;
            }
        
        int low=1,high=arr.size()-2;
        int maxi=INT_MIN,mind=-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(arr[mid+1]<arr[mid] && arr[mid-1]<arr[mid]){
                return mid;
            }
            else if(arr[mid-1]<=arr[mid] && arr[mid]<=arr[mid+1] ){
                low=mid+1;
            }else {
                
                high=mid-1;
            }
        }
        return 0;
    }
};