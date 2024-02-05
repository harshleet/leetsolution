class Solution {
public:
    void lpsFinder(string &str,vector<int>&lps){
         lps[0]=0;
         int i=1,len=0;

         while(i<str.length()){
             if(str[i]==str[len]){
                 len++;
                 lps[i]=len;
                 i++;
             }else{
                 if(len==0){
                     lps[i]=0;
                     i++;
                 }else{
                     len=lps[len-1];
                 }
             }
         }
    }
    string longestPrefix(string s) {
        vector<int>lps(s.size());
        lpsFinder(s,lps);
       
        return s.substr(0,lps.back());
         

    }
};