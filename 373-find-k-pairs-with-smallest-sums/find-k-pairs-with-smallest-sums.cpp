class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({nums1[0]+nums2[0],0,0});
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>>ans;
        map<pair<int,int>,int>vis;

        vis[{0,0}]=1;
        while(k>0){
            int ind1=get<1>(pq.top());
            int ind2=get<2>(pq.top());
            pq.pop();
            ans.push_back({nums1[ind1],nums2[ind2]});
            k--;
            
            if(ind1+1<n && vis.find({ind1+1,ind2})==vis.end()){
                vis[{ind1+1,ind2}]=1;
                pq.push({nums1[ind1+1]+nums2[ind2],ind1+1,ind2});
            }

            if(ind2+1<m && vis.find({ind1,ind2+1})==vis.end()){
                vis[{ind1,ind2+1}]=1;
                pq.push({nums1[ind1]+nums2[ind2+1],ind1,ind2+1});
            }
        }
        return ans;
    }
};