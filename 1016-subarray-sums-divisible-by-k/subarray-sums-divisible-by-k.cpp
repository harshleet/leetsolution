class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0]++;

        int sum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            // cout<<sum<<" "<<(k+(sum%k))%k<<endl;
            if(mp.find((k+(sum%k))%k)!=mp.end()){
                cnt+=mp[(k+(sum%k))%k];
            }
            mp[(k+(sum%k))%k]++;
        }
        return cnt;
    }
};