class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int mini=INT_MAX;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
               m[nums[i]]++;
               mini=min(mini,nums[i]);
        }
        int sz=m.size()-1;
        int st=0;
        for(auto it = m.rbegin(); it != m.rend(); it++){
            if(it->first!=mini){
                 st+=(it->second)*sz;
                 sz--;
                //   cout<<it.first<<" "<<it.second<<" "<<sz<<" ";
            }
        }
        return st;
    }
};