class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
       vector< long long int>suf(n);
       vector< long long int>pre(n);
       long long int sufp=1,prep=1,maxi=INT_MIN;
       for(int i=0;i<n;i++){
        if(sufp<=-1e9){
            sufp=1;
        }
        if(prep<=-1e9){
            prep=1;
        }
        sufp*=nums[i];
        prep*=nums[n-1-i];
        maxi=max(maxi,sufp);
        maxi=max(maxi,prep);
        if(sufp==0){
            sufp=1;
        }
        if(prep==0){
            prep=1;
        }
        // suf[i]=sufp;
        // pre[i]=prep;
        
       }
       return maxi;
    }
};