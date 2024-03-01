class Solution {
public:
    // int mcnt=0;
    //  map<tuple<int,vector<int>,vector<int>>,int>m;
    // int helper(int sec,vector<int>&nums,vector<int>& changeIndices, vector<int>&vis){
    //     if(mcnt==nums.size()){
    //         return sec;
    //     }
    //     if(sec>=changeIndices.size()){
    //         return INT_MAX;
    //     }
    //     if(m[{sec,vis,nums}]!=0){
    //         return m[{sec,vis,nums}];
    //     }
    //     int cnt=INT_MAX;
    //     if(!vis[changeIndices[sec]-1] && nums[changeIndices[sec]-1]==0){
    //         vis[changeIndices[sec]-1]=1;
    //         mcnt++;
    //         cnt=min(cnt,helper(sec+1,nums,changeIndices,vis)); 
    //         vis[changeIndices[sec]-1]=0;
    //         mcnt--;
    //     }
        
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]>0){
    //             nums[i]--;
    //             cnt=min(cnt,helper(sec+1,nums,changeIndices,vis));
    //             nums[i]++;
    //         }
    //     }
    //     cnt=min(cnt,helper(sec+1,nums,changeIndices,vis)); 
    //     return m[{sec,vis,nums}]=cnt;
    // }
    bool helper(int time,vector<int>& nums, vector<int>& changeIndices){
       map<int,int>m;
       for(int i=0;i<=time;i++){
           m[changeIndices[i]-1]=i;
       }
       int op=0,marked=0;
       for(int i=0;i<=time;i++){
          if(m.find(changeIndices[i]-1)==m.end() || m[changeIndices[i]-1]!=i){
              //deletion operation in this
              op++;
          }else if(m[changeIndices[i]-1]==i){
              if(op>=nums[changeIndices[i]-1]){
                  op-=nums[changeIndices[i]-1];
                  marked++;
              }else{
                  return false;
              }
          }
       }
       return nums.size()==marked;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
       
        // vector<int>vis(nums.size(),0);
        // int s=0;
        // int cnt=helper(0,nums,changeIndices,vis);
        
        // if(cnt==INT_MAX){
        //     return -1;
        // }
        // return cnt;
        int low=0,high=changeIndices.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(helper(mid,nums,changeIndices)){
                ans=mid+1;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};