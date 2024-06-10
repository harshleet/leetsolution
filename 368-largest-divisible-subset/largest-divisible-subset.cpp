class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //print it
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>ha(n,-1);
        int gmax=1,gmaxii=0;
        for(int ind=1;ind<nums.size();ind++){
            int maxi=1,maxii=ind;
            for(int pre=ind-1;pre>=0;pre--){
                if(nums[ind]%nums[pre]==0 ){
                    if(1+dp[pre]>maxi){
                        maxi=1+dp[pre];
                        maxii=pre;
                    }
                }
            }
           
            dp[ind]=maxi;
            if(maxii!=ind){
              ha[ind]=maxii;
            }
            if(maxi>gmax){
                gmax=maxi;
                gmaxii=ind;
            }
        }
        vector<int>ans;
        while(ha[gmaxii]!=-1){
            ans.push_back(nums[gmaxii]);
            gmaxii=ha[gmaxii];
        }
        ans.push_back(nums[gmaxii]);
        reverse(ans.begin(),ans.end());
    return ans;
       
    }
};