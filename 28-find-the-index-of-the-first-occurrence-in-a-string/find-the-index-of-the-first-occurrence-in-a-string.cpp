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
    int strStr(string txt, string pat) {
         int n=pat.size();
            vector<int>lps(n,0);
            lps_fill(pat,lps);
           
            int j=0,i=0;
            while(i<txt.size()){
                if(pat[j]==txt[i]){
                    i++;
                    j++;
            
                     if(j==n){
                        return i-n;
                        j=lps[j-1];
                    }
                }else{
                    if(j!=0){
                        j=lps[j-1];
                    }else{
                        i++;
                    }
                }
               
            }
            return -1;
    }
};