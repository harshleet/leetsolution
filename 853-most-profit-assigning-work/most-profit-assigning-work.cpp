class Solution {
public:

   int ub(vector<pair<int,int>>&dpr,int val){
    int lo=0,hi=dpr.size()-1,ans=hi+1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(dpr[mid].first>val){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return ans;
   }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();
        vector<pair<int,int>>dpr;
        for(int i=0;i<n;i++){
            dpr.push_back({difficulty[i],profit[i]});
        }
        sort(dpr.begin(),dpr.end());
        vector<int>maxp(n,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dpr[i].second);
            maxp[i]=maxi;
        }
        int ans=0;
        for(int i=0;i<worker.size();i++){
            int ind=ub(dpr,worker[i]);
            // cout<<ind<<" ";
            if(ind!=0){
                ans+=maxp[ind-1];
            }
        }
        return ans;
    }
};