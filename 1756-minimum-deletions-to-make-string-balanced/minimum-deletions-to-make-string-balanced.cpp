class Solution {
public:
    int minimumDeletions(string s) {
        int ac=0,bc=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                ac++;
            }else{
                bc++;
            }
        }

        int ta=0,tb=0,mini=INT_MAX;
        mini=min(mini,ac);
        mini=min(mini,bc);
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                ta++;
            }else{
                tb++;
            }
            mini=min(mini,tb+ac-ta);
        }
        return mini;
    }
};