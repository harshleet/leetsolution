class Solution {
public:
    bool possible(string &a,string &b){
    
        if(a.size()-b.size()!=1){
            return false;
        }
        int i=0,j=0;
        int diff=0;
        while(i<a.size() && j<b.size()){
            if(a[i]!=b[j]){
                i++;
                diff++;
            }else{
                i++;
                j++;
            }
            
        }
        
        return diff<=1;
    }
    int helper(int ind,int pre,vector<string>&words,vector<vector<int>>&dp){
        if(ind>=words.size()){
            return 0;
        }
        if(dp[ind][pre+1]!=-1){
            return dp[ind][pre+1];
        }
        int nt=helper(ind+1,pre,words,dp);
        int t=0;
        if(pre==-1 || possible(words[ind],words[pre])){
            t=1+helper(ind+1,ind,words,dp);
        }
        return dp[ind][pre+1]=max(nt,t);
    }
    int longestStrChain(vector<string>& words) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        for(int i=0;i<words.size();i++){
            pq.push({words[i].size(),words[i]});
        }
        vector<string>temp;
        while(!pq.empty()){
           
            temp.push_back(pq.top().second);
            pq.pop();
        }
        vector<vector<int>>dp(words.size(),vector<int>(words.size(),-1));
        return helper(0,-1,temp,dp);
    }
};