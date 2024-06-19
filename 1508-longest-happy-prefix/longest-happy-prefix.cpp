class Solution {
public:

void lps_fill(string pat,vector<int>&lps){
            int i=1,len=0;
            while(i<lps.size()){
                if(pat[i]==pat[len]){
                   
                    len++;
                    lps[i]=len;
                    i++;
                }else{
                    if(len!=0){
                        len=lps[len-1];
                    }else{
                        lps[i]=0;
                        i++;
                    }
                }
            }
     }
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps(n,0);
        lps_fill(s,lps);
        int lind=lps[n-1];
        return s.substr(0,lind);
    }
};