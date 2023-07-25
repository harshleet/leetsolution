class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0,high=arr.size();
        int mid;
         while(low<high){
            mid=(low+high)/2;
            if(arr[mid]>arr[mid+1]){
                high=mid;
            }
            else{
                low=mid+1;
            }
         }
         return high;
    }
};