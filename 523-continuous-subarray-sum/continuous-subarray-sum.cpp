class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>pre(n+1);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }
        map<int,int>mod;
        mod[0]=0;
        for(int i=0;i<n;i++){
            int rem=pre[i+1]%k;
            if(rem==0 && i!=0){
                return true;
            }else if(mod.find(rem)!=mod.end() && mod[rem]<i-1){
                return true;
            }else if(mod.find(rem)==mod.end() ){
                mod[rem]=i;
            }
        }
        return false;
    }
};