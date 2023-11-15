class Solution {
public:
    // bool check(int mid,vector<int>& arr){
    //     arr[0]=1;
    //     for(int i=1;i<arr.size();i++){

    //         if(abs(arr[i]-arr[i-1])>1){
    //                  arr[i]=arr[i-1]+1;
    //         }
    //         if(arr[i]==mid){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        if(arr.size()==1){
            return 1;
        }
        sort(arr.begin(),arr.end());
        arr[0]=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]>1){
                arr[i]=arr[i-1]+1;
            }
        }
        return arr.back();
       
    }
};