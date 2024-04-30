class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans=0;
        map<int,int>m;
        int pre=0;
        m[0]++;
        for(int i=0;i<word.size();i++){
            pre^=(1<<(word[i]-'a'));
            ans+=m[pre];
            
            for(char j='a';j<='j';j++){
                int odd=pre^(1<<(j-'a'));
                ans+=m[odd];
                
            }
            m[pre]++;
            
        }
        return ans;
    }
};