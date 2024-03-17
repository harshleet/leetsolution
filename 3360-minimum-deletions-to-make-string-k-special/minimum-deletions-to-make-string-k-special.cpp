class Solution {
public:
     int helper(int l,int r,vector<int>&v,int k,vector<vector<int>>&dp){
        if(l==r){
            return 0;
        }
        if(v[r]-v[l]<=k){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        return dp[l][r]=min(v[l]+helper(l+1,r,v,k,dp),v[r]-v[l]-k+helper(l,r-1,v,k,dp));
     }
    int minimumDeletions(string word, int k) {
        map<char,int>m;
        for(int i=0;i<word.size();i++){
            m[word[i]]++;
        }
        vector<int>v;
        for(auto it:m){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        vector<vector<int>>dp(v.size(),vector<int>(v.size(),-1));
        return helper(0,v.size()-1,v,k,dp);
        // long long ans=0;
        // int low=0,high=v.size()-1;
        // while(low<high){
        //     if(v[high]-v[low]<=k){
        //         high--;
        //     }else{
        //         if(((v[high]-v[low])-k)<v[low]){
        //              ans+=((v[high]-v[low])-k);
        //             v[high]-=((v[high]-v[low])-k);
        //             high--;
        //         }else{
        //             ans+=v[low];
        //             v[low]=0;
                    
        //             low++;
        //         }
        //     }
            
        // }
        // return ans;
    }
};