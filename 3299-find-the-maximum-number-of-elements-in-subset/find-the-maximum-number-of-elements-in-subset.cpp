class Solution {
public:
    long long int helper(long long int val,map<long long int,long long int>&m,map<long long int,long long int>&dp){
        if(dp.find(val)!=dp.end()){
            return dp[val];
        }
        long long int maxi=1;
        if(m[val]>=2 && m[val*val]!=0){
            maxi=max(maxi,2+helper(val*val,m,dp));
        }
        return dp[val]=maxi;
    }
    int maximumLength(vector<int>& nums) {
        map<long long int,long long int>m;
        map<long long int,long long int>dp;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        long long int maxi=1;
        if(m[1]%2==1){
            maxi=max(maxi,m[1]);
        }else{
            maxi=max(maxi,m[1]-1);
        }
        
        for(auto it:m){
            if(it.first==1){
                continue;
            }
            if(dp.find(it.first)==dp.end()){
                maxi=max(maxi,helper(it.first,m,dp));
            }
        }
        return maxi;
        
    }
};