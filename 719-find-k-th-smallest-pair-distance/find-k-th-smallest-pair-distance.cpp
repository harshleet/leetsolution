class Solution {
public:
    bool isPossible(int mid,int k,vector<int>&nums){
        int total=0;
      int j=0,n=nums.size();
      for(int i=0;i<n;i++){
        while(j<n && nums[j]-nums[i]<=mid)j++;
        j--;
        total+=(j-i);
      }
      return total>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        //llook for all pairs in nlogn
        // vector<int,vector<int>,greater<int>>pq;
       //merge sort try lkar skte
       //all pairs
       sort(nums.begin(),nums.end());
       int l=0,h=nums.back()-nums[0];
int ans=0;
       while(l<=h){
        int mid=(l+h)/2;
            if(isPossible(mid,k,nums)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
       }
       return ans;

    }
};