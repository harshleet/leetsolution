class Solution {
public:
    int characterReplacement(string s, int k) {
        int j=0,maxf=0;
        vector<int>fre(26,0);

        int ans=0;
        for(int i=0;i<s.size();i++){
            fre[s[i]-'A']++;
            maxf=max(maxf,fre[s[i]-'A']);

            while((i-j+1-maxf)>k && j<=i){
                fre[s[j]-'A']--;
                int maxi=0;
                for(int k=0;k<26;k++){
                    maxi=max(maxi,fre[k]);
                    
                }
                maxf=maxi;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};