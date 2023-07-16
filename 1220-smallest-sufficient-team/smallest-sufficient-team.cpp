class Solution {
public:
    vector<int> res;
    
    void helper(vector<string>& req_skills,vector<int>&bitpeo, int bitmask, vector<vector<int>>& dp, int ind, vector<int>& ans) {
        int n = req_skills.size();
        if (ind == bitpeo.size()) {
            if (bitmask == (1 << n) - 1) {
                if (res.empty() || ans.size() < res.size()) {
                    res = ans;
                    
                }
            }
            return;
        }
        
        if (dp[ind][bitmask] != -1 && dp[ind][bitmask] <= ans.size() ) {
            return;
        }
        
         helper(req_skills, bitpeo, bitmask, dp, ind + 1, ans);
     
        ans.push_back(ind);
      helper(req_skills, bitpeo, bitmask|bitpeo[ind], dp, ind + 1, ans);
        ans.pop_back();
        if(ans.size() > 0){
            dp[ind][bitmask]=ans.size();
        }
       
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        map<string, int> m;
        
        for (int i = 0; i < req_skills.size(); i++) {
            m[req_skills[i]] = i;
        }
        
        int n = req_skills.size();
        int bitmask = 0;
        vector<int> ans;
        vector<vector<int>> dp(people.size(), vector<int>(1 << n, -1));
        vector<int>bitpeo(people.size());
        for(int ind=0;ind<people.size();ind++){
           bitmask = 0;
            for (int i = 0; i < people[ind].size(); i++) {
                int val = m[people[ind][i]];
                
                if ((bitmask & (1 << val)) == 0) {
                    bitmask |= (1 << val);
                }
            }
            bitpeo[ind]=bitmask;
        }
        bitmask=0;
       helper(req_skills, bitpeo, bitmask, dp, 0, ans);
        
        return res;
    }
};
