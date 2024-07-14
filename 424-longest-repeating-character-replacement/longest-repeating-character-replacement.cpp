class Solution {
public:
    int characterReplacement(string s, int k) {
        int j=0;
        vector<int>mp(26,0);
        int tot=0,maxi=0,maxf=0;


        for(int i=0;i<s.size();i++){
            mp[s[i]-'A']++;
            maxf=max(maxf,mp[s[i]-'A']);
            while(i-j+1-maxf>k && j<=i){
                mp[s[j]-'A']--;
                j++;
                maxf=0;
                for(int m=0;m<26;m++){
                    maxf=max(maxf,mp[m]);
                }
            }
            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};