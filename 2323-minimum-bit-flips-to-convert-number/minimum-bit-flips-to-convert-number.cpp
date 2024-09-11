class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start^goal;
        string s=bitset<31>(x).to_string();
        int ans=0;
        for(int i=0;i<31;i++){
            if(s[i]=='1'){
                ans++;
            }
        }
        return ans;
    }
};