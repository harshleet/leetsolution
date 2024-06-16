class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int sum=0,ans=0,ach=1,i=0;
        while(sum<n){
           if(i<nums.size() && sum+1>=nums[i]){
             sum+=nums[i];
             ach=sum+1;
             i++;
          
           }else{
            // cout<<ach<<" "<<sum<<" "<<nums[i]<<"b"<<endl;
            //   cout<<ach<<" "<<sum<<" "<<nums[i]<<"a"<<endl;
            ans++;
            sum+=sum+1;
            ach++;
           }
        }
        return ans;
    }
};