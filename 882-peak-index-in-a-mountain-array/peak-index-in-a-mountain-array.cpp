class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(arr[0]>arr[1]){
            return 0;
        }
        if(arr.back()>arr[n-2]){
            return n-1;
        }

        int low=1,high=n-2;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;

            if(arr[mid]>arr[mid-1] || arr[mid]<arr[mid+1]){
                ans=mid;
                low=mid+1;
            }else if(arr[mid]>arr[mid+1] || arr[mid-1]>arr[mid]){
                high=mid-1;
            }

        }
        return ans;
    }
};