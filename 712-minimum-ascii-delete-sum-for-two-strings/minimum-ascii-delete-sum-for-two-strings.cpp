class Solution {
public:
    int getSumOfAscii(const std::string& inputString) {
        int asciiSum = 0;

        // Iterate over each character in the string
        for (char c : inputString) {
            // Add the ASCII value of the character to the sum
            asciiSum += static_cast<int>(c);
        }

        return asciiSum;
    }
    int f(string& s1,string& s2,int i,int j,vector<vector<int>>&dp){
           if(i<0 || j<0){
               return 0;
           }
           if(dp[i][j]!=-1){
               return dp[i][j];
           }
           int ntake=max(f(s1,s2,i-1,j,dp),f(s1,s2,i,j-1,dp));
           int take=0;
           if(s1[i]==s2[j]){
               take=s1[i]+f(s1,s2,i-1,j-1,dp);
           }
           return dp[i][j]=max(ntake,take);

    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.length(),vector<int>(s2.length(),-1));
        int lcs=f(s1,s2,s1.size()-1,s2.size()-1,dp);
        cout<<lcs<<endl;
        int val=getSumOfAscii(s1)+getSumOfAscii(s2)-2*lcs;
        return val;
    }
};