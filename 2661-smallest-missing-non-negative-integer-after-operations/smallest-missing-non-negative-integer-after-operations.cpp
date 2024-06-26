class Solution {
public:
//         bool isPos(int mid,vector<int>&nums,int value){
                
//         }
    int findSmallestInteger(vector<int>& nums, int value) {
        // int l=0,h=nums.size();
        //     int ans=-1;
        //     while(l<=h){
        //             int mid=(l+h)/2;
        //             if(isPos(mid,nums,value)){
        //                     // cout<<mid<<" ";
        //                     ans=mid;
        //                     l=mid+1;
        //             }else{
        //                     h=mid-1;
        //             }
        //     }
        //     return ans+1;
                map<int,int>m;
                for(int i=0;i<nums.size();i++){
                      m[((value+(nums[i])%value))%value]++;
                        // cout<<abs(value+nums[i])%value<<" ";
                }
                int maxi=0;
                for(int i=0;i<=nums.size();i++){
                        if(m[(i%value)]>0){
                                m[(i%value)]--;
                        }else{
                               maxi=max(maxi,i);
                                break;
                        }
                }
                return maxi; 
    }
};