class Solution {
public:
   bool isPossible(vector<int>& piles,int k, int h){
       long long int p=0;
       for(int i=0;i<piles.size();i++){
           p+=ceil(piles[i]/(double)k);
       }
       return p<=h;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int low=1,high=piles.back(),ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};