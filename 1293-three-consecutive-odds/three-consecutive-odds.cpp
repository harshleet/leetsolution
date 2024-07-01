class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()<=2){
            return false;
        }
        int sum=0;
        for(int i=0;i<3;i++){
            sum+=arr[i];
        }
        if(sum%2==1 && (arr[0]+arr[1])%2==0 & (arr[2]+arr[1])%2==0){
            return true;
        }
        for(int i=3;i<arr.size();i++){
            sum-=arr[i-3];
            sum+=arr[i];
            if(sum%2==1  && (arr[i]+arr[i-2])%2==0 & (arr[i-2]+arr[i-1])%2==0){
               return true;
           }
        }
        return false;
    }
};