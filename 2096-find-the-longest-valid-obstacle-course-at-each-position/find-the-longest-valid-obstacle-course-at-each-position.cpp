class Solution {
public:
    int helper(int ind,int prev,vector<int>&ob,vector<vector<int>>&dp){
        if(ind>=ob.size()){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int nt=helper(ind+1,prev,ob,dp);
        int t=0;
        if(prev==-1 || ob[ind]>=ob[prev]){
            t=1+helper(ind+1,ind,ob,dp);
        }
        return dp[ind][prev+1]=max(t,nt);

    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>ans;
        vector<int> temp;
        temp.push_back(obstacles[0]);

        int len = 1,n=obstacles.size();
        ans.push_back(len);
        for (int i = 1; i < n; i++) {
            if (obstacles[i] >= temp.back()) {
                temp.push_back(obstacles[i]);
                len++;
                ans.push_back(len);
            } else {
                int ind = upper_bound(temp.begin(), temp.end(), obstacles[i]) - temp.begin();
                temp[ind] = obstacles[i];
                ans.push_back(ind+1);
            }
            
        }

        return ans;
    }
};