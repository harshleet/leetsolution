class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),ne=0;
        int pro=1;
        // for(int i=0;i<n;i++){
        //    if(nums[i]<0){
        //     ne++;
        //    }
        //    pro*=nums[i];
        // }
        // if(ne%2==0){
        //     return pro;
        // }
        if(nums.size()==1){
            return nums[0];
        }
        int st=ne,en=ne,ps=1,pe=1,maxi=0;
        for(int i=0;i<n;i++){
            if(ps==0){
                ps=1;
            }
            if(pe==0){
                pe=1;
            }
            ps*=nums[i];
            pe*=nums[n-1-i];
            maxi=max(maxi,ps);
            maxi=max(maxi,pe);
        }
        return maxi;
    }
};