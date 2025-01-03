class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long  tsum=0;
        vector<long long int>pre(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            pre[i+1]=pre[i]+nums[i];
        }
        tsum=pre.back();

        long long  ans=0;

        for(int i=0;i<nums.size()-1;i++){
            long long  val=pre[i+1];
            long long  val2=tsum-val;
            if(val>=val2){
                ans++;
            }
        }
        return ans;

    }
};