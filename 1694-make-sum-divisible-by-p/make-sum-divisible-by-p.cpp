class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long int sum=0;
        vector<long long int>pre(nums.size()+1,-1);
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
        }
        long long int rem=sum%p;
        
        if(rem==0){
            return 0;
        }
        cout<<rem<<" ";
        //now to find the min subarray

        map<long long int,long long int>mp;
        mp[0]=-1;
        long long int s=0,mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            // cout<<s%rem<<" ";
            long long val=(p-(sum)%p+s%p)%p;
            // cout<<val<<" ";
            if(mp.find(val)!=mp.end() && i-mp[val]!=nums.size()){
                mini=min(mini,i-mp[val]);
            }
            mp[s%p]=i;
        }

        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};