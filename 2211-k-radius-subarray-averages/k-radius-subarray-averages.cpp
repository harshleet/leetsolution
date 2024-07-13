class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0){
            return nums;
        }
        int n=nums.size();
        vector<long long>prefix(n);
        long long s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            prefix[i]=s;
        }
        vector<int>ans(n,-1);
        vector<bool> vis(n, false);
      
        
        for(int i=min(k,n);i<min(n,n-k);i++){
           
            int upto=min(n-1,k+i);
            int from=max(i-k-1,0);
            long long presum=prefix[upto];
             if(i-k-1>=0){
                    presum-=prefix[i-k-1];
             }
            int avg=(presum)/(2*k+1);
            ans[i]=(avg);
            vis[i] = true;
        }
          
        return ans;
    }
};