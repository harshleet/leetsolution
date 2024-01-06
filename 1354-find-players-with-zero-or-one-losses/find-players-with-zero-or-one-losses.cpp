class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>m1;
        map<int,int>m2;
        vector<vector<int>>ans(2);
        for(int i=0;i<matches.size();i++){
            if(m2.find(matches[i][0])==m2.end()){
                m1[matches[i][0]]++;
            }
            m2[matches[i][1]]++;
            if(m1.find(matches[i][1])!=m1.end()){
                m1.erase(matches[i][1]);
            }
        }
        for(auto it:m1){
                ans[0].push_back(it.first);
        }
        for(auto it:m2){
           if(it.second==1){
                ans[1].push_back(it.first);
            }
        }
        return ans;
    }
};