class Solution {
public:
 bool check(int mid,vector<int>&piles,long long int h){
     long long int time=0;
     for(int i=0;i<piles.size();i++){
       time+=ceil(double(piles[i]/(double(mid))));
     }
     return time<=h;
 }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int low=1,high=piles.back();
       int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};