class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int st=0 ,en=0,maxi=INT_MIN,sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>=maxi){
                maxi=sum;
                en=i;
            }
            if(sum<0){
                st=i+1;
                sum=0;
            }
        }
        vector<int>ans;
        // if( en==-1){
        //     return {-1};
        // }
     
        for(int i=st;i<=en;i++){
            cout<<nums[i]<<" ";
        }
        return maxi;
    }
};