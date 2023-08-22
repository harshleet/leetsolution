class Solution {
public:
    bool possible(int day,vector<int>&bloomDay,int m,int k){
        int cnt=0;
        int bou=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                cnt++;
            }else{
                bou+=(cnt/k);
                cnt=0;
            }
        }
         bou+=(cnt/k);
        if(bou>=m){
            return true;
        }return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low=mini;
        int high=maxi;
        bool f=false;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(mid,bloomDay,m,k)){
                high=mid-1;
                f=true;
            }else{
                low=mid+1;
            }
        }
        if(f==false){
            return -1;
        }
        return low;
    }
};