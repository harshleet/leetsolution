class Solution {
public:
    void helper(int ind,int val,int &ans,vector<int>&nums,int maxi){
        if(ind==nums.size()){
            if(val==maxi){
                ans++;
            }
            return;
        }
        helper(ind+1,val,ans,nums,maxi);
        int pre=val;
        val|=nums[ind];
        helper(ind+1,val,ans,nums,maxi);
        val=pre;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi|=nums[i];
        }
        int ans=0;
        helper(0,0,ans,nums,maxi);
        return ans;
    }
};