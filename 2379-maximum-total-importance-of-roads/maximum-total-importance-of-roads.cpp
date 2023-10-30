class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int>ind;
        for(int i=0;i<roads.size();i++){
            ind[roads[i][0]]++;
            ind[roads[i][1]]++;
        }
        vector<pair<int,int>>indegree;
        for(auto it:ind){
            indegree.emplace_back(it.second,it.first);
        }

        sort(indegree.begin(),indegree.end());
        int i=n;
        vector<int>ans(n);

        for(auto it = indegree.rbegin(); it != indegree.rend(); ++it) {
            ans[it->second]=i;
            i--;
        }
        long long a=0;
         for(int i=0;i<roads.size();i++){
            a+=ans[roads[i][0]];
           a+= ans[roads[i][1]];
        }
        return a;
    }
};