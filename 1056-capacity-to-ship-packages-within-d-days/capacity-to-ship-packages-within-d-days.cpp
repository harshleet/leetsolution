class Solution {
public:
   bool isPos(int cap,vector<int>&weights,int days){
    int temp=cap,cnt=1;
    int maxi=0;
    for(int i=0;i<weights.size();i++){
        if(cap-weights[i]>=0){
            cap-=weights[i];
        }else{
            cap=temp;
            cap-=weights[i];
            cnt++;
        }
    }
    return cnt<=days;
   }
    int shipWithinDays(vector<int>& weights, int days) {
        // sort(weights.begin(),weights.end());
        int low=*max_element(weights.begin(),weights.end()),high=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;

            if(isPos(mid,weights,days)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};