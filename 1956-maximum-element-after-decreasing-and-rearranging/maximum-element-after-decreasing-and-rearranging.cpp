class Solution {
public:
    bool check(int mid,vector<int>& arr){

        arr[0]=1;
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1])>1){
                 if(arr[i]>arr[i-1]+1){
                     arr[i]=arr[i-1]+1;
                 }
            }
            if(arr[i]==mid){
                return true;
            }
        }
        return false;
    }
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        if(arr.size()==1){
            return 1;
        }
        if(arr.size()==2){
            if(arr.back()>1){
                return 2;
            }
            return 1;
        }
        sort(arr.begin(),arr.end());
        int low=1,high=arr.back();

        while(low<=high){
            int mid=(low+high)/2;

            if(check(mid,arr)){
                  low=mid+1;
            }else{
                 high=mid-1;
            }
        }
        return low-1;
    }
};