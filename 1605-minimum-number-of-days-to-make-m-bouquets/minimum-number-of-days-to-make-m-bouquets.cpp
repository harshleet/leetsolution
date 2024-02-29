class Solution {
public:
    bool isPossible(int mid,vector<int>& bloomDay, int m, int k){
        int size=0,cnt=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                size++;
            }else{
                size=0;
            }
            if(size==k){
                cnt++;
                size=0;
            }

        }
        return cnt>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1,high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(mid,bloomDay,m,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};