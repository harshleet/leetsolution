class Solution {
public:
    int dig(int num){
        int ans=0;
        while(num!=0){
            int val=num%10;
            num/=10;
            ans+=val;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        map<int,int>mp;
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            int dig_sum=dig(nums[i]);

            if(mp.find(dig_sum)!=mp.end()){
                maxi=max(maxi,mp[dig_sum]+nums[i]);
                if(mp[dig_sum]<nums[i]){
                    mp[dig_sum]=nums[i];
                }
            }else{
                mp[dig_sum]=nums[i];
            }
        }
        return maxi;
    }
};