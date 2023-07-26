class Solution {
public:
    bool isPossible(vector<int>& dist, double& hour,int& speed){
        double ans=0;
        for(int i=0;i<dist.size();i++){
            double d=dist[i]*1.0/speed;
            if(i!=dist.size()-1)
            ans=ans+ceil(d);
            else
            ans+=d;
            if(ans>hour)
            return false;
        }
       if(ans<=hour)
       return true;
       return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1;
        int high=1e7;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
              if(isPossible(dist,hour,mid)){
                  high=mid-1;
                  ans=mid;
              }else{
                  low=mid+1;
              }
        }
        return ans;
    }
};