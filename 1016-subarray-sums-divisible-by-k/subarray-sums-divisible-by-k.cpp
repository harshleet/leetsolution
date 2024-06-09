class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>m;
        int ans=0;
        vector<int>pre(nums.size());
        for(int i=0;i<nums.size();i++){
            
            if(i==0){
                pre[i]=nums[i];
            }else{
                pre[i]=nums[i]+pre[i-1];
            }
        }
        
        for(int i=0;i<nums.size();i++){
            cout<<pre[i]%k<<" ";
            if((k+(pre[i]%k))%k==0){
              ans++;
            }
            if(m.find((k+(pre[i]%k))%k)!=m.end()){
                ans+=m[(k+(pre[i]%k))%k];
            }
            m[(k+(pre[i]%k))%k]++;
        }
        return ans;
        
    }
};