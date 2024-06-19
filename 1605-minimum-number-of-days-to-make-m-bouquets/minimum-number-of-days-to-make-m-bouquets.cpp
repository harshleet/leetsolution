class Solution {
public:
    int isPos(int mid,vector<int>&bloomDay,int m,int k){
        int cnt=0,a=0;
        // for(int i=0;i<k;i++){
        
        // }
        for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                   cnt++;
                }else{
                    cnt=0;
                }
                if(cnt==k){
                    a++;
                    cnt=0;
                }
        }
        return a>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1,high=*max_element(bloomDay.begin(),bloomDay.end()),ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPos(mid,bloomDay,m,k)){
                ans=mid;
                 high=mid-1;
            }else{
                 low=mid+1;
            }
        }
        return ans;
    }
};