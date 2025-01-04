class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>left(26,-1);
        vector<int>right(26,-1);

        int n=s.size();
        for(int i=0;i<n;i++){
            if(left[int(s[i]-'a')]==-1){
                left[int(s[i]-'a')]=i;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(right[int(s[i]-'a')]==-1){
                right[int(s[i]-'a')]=i;
            }
        }

        int ans=0;
        for(int i=0;i<26;i++){
            if(left[i]!=-1 && right[i]!=-1){
                vector<int>temp(26,-1);
                int val=0;
                for(int j=left[i]+1;j<right[i];j++){
                    if(temp[int(s[j]-'a')]==-1){
                        temp[int(s[j]-'a')]=i;
                        val++;
                    }
                }
                ans+=val;
            }
        }
        return ans;
    }
};