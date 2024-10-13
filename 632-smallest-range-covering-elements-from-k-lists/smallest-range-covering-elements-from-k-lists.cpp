class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                v.push_back({nums[i][j],i});
            }
        }
        sort(v.begin(),v.end());

        map<int,int>mp;
        int j=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i=0;i<v.size();i++){
            // cout<<v[i].first<<" "<<v[i].second<<" "<<i<<endl;
            mp[v[i].second]++;
            while(mp.size()==nums.size() && i>=j){
                // cout<<j<<" "<<i<<endl;
                pq.push({v[i].first-v[j].first,v[j].first,v[i].first});
                mp[v[j].second]--;
                if(mp[v[j].second]==0){
                    mp.erase(v[j].second);
                }
                j++;
            }
            
        }

        return {pq.top()[1],pq.top()[2]};
    }
};