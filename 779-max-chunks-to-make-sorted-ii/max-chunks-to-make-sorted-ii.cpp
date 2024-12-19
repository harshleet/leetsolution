class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<pair<int,int>>temp;

        for(int i=0;i<arr.size();i++){
            temp.push_back({arr[i],i});
        }

        sort(temp.begin(),temp.end());
        map<int,int>mp;
        for(int i=0;i<temp.size();i++){
         
                mp[temp[i].second]=i;
        }
        int l=0,cnt=0;
        for(int i=0;i<arr.size();i++){
            l=max(mp[i],l);
            if(l<=i){
                cnt++;
            }
        }
        return cnt;
    }
};