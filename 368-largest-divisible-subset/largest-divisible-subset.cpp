class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        int maxi=0,last=-1;
        for(int i=0;i<nums.size();i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j]==0 || nums[j]%nums[i]==0) && 1+dp[j]>dp[i] ){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }
        }
        cout<<maxi<<" "<<last<<endl;
        // if(last==)
        vector<int>ans;
        
        while(hash[last]!=last){
            
            ans.push_back(nums[last]); 
            last=hash[last];   
        }
        ans.push_back(nums[last]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};