class Solution {
public: 
    bool isPos(int mid,vector<int>& position, int m){
        int pre=-1,c=0;
        for(int i=0;i<position.size();i++){
            if(pre==-1 || position[i]>=pre+mid){
                c++;
                pre=position[i];
            }
        }
        return c>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=1,high=position.back(),ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPos(mid,position,m)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};