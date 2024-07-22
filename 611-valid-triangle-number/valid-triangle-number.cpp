class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,n=nums.size();
        for(int i=n-1;i>=2;i--){
            int st=i-1;
            int j=0;
            while(j<st){
                if(nums[i]>=nums[st]+nums[j]){
                    j++;
                }else{
                    ans+=st-j;
                    st--;
                }
            }
        }
        return ans;
    }
};