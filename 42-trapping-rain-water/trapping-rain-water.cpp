class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        vector<int>maxr(n,-1);
        vector<int>maxl(n,-1);
        for(int i=0;i<n;i++){
            if(i==0){
                maxl[i]=nums[i];
                maxr[n-1-i]=nums[n-1-i];
            }else{
            maxl[i]=max(maxl[i-1],nums[i]);
            maxr[n-i-1]=max(maxr[n-i],nums[n-i-1]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            cout<<maxl[i]<<" "<<maxr[i]<<endl;
            if(maxl[i]!=-1 && maxr[i]!=-1){
                int mini=min(maxl[i],maxr[i]);
                ans+=mini-nums[i];
            }
        }
        return ans;
    }
};