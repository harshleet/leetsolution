class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0,cnt=0;
        map<int,int>m;
        int j=0;
        for(int i=0;i<nums.size();i++){
            cnt+=m[nums[i]];
            m[nums[i]]++;
            cout<<cnt<<" ";
            while(cnt>=k && j<=i){
                ans+=nums.size()-i;
                m[nums[j]]--;
                cnt-=(m[nums[j]]);
                j++;
            }

        }
        return ans;
    }
};