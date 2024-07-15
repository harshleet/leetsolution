class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int,int,int>>pq;

        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(pq.size()<k){
                    pq.push({nums1[i]+nums2[j],nums1[i],nums2[j]});
                }else if(get<0>(pq.top())>nums1[i]+nums2[j]){
                    pq.pop();
                    pq.push({nums1[i]+nums2[j],nums1[i],nums2[j]});
                }else{
                    break;
                }
            }
        }
        vector<vector<int>>ans;

        while(!pq.empty()){
            ans.push_back({get<1>(pq.top()),get<2>(pq.top())});
            pq.pop();
        }
        return ans;
    }
};