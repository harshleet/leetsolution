class Solution {
public:
int cal(vector<int>&nums,int k){
       
        int odd=0;
        vector<int>prefix(nums.size());
        for(int i=0;i<nums.size();i++){
           
            prefix[i]=nums[i]%2;
            cout<<prefix[i]<<" ";
        }
         int j=0;
       int sum=0;
       int cnt=0;
       for(int i=0;i<prefix.size();i++){
           if(prefix[i]==1){
               sum+=prefix[i];
           }
         
           while(sum>k && j<prefix.size()){
               sum-=prefix[j];
               j++;
           }
           cnt+=i-j+1;
       }
        return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
           return cal(nums,k)-cal(nums,k-1);
    }
};