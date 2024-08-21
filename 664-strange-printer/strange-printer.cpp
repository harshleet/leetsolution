class Solution {
public:
int dp[101][101];
    int helper(int st,int en,string &s){
        // cout<<st<<" "<<en<<endl;
       
        if(st>en){
            return 0;
        }

        if(dp[st][en]!=-1){
            return dp[st][en];
        }
        int t=1+helper(st+1,en,s);

        for(int i=st+1;i<=en;i++){
            if(s[st]==s[i]){
                t=min(t,helper(st+1,i-1,s)+helper(i,en,s));
            }
            
        }
        return dp[st][en]=t;
    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        s.erase(unique(s.begin(), s.end()), s.end());
        cout<<s<<endl;
        return helper(0,s.size()-1,s);
    }
};