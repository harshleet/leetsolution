class Solution {
public:
    int maxScore(string s) {
        vector<int>pre(s.size(),0);

        if(s[0]=='0'){
            pre[0]=1;
        }
        for(int i=1;i<s.size();i++){
            if(s[i]=='0'){
                pre[i]=pre[i-1]+1;
            }else{
                pre[i]=pre[i-1];
            }
        }
        int maxi=0;
        for(int i=0;i<s.size()-1;i++){
            int zr=pre[i];
            int on=(s.size()-i-1)-(pre.back()-pre[i]);
            
            maxi=max(maxi,zr+on);
        }
        return maxi;

    }
};