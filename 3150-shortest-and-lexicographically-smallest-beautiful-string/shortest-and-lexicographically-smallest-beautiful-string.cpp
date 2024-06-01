class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int mini=INT_MAX;
        string st="";
        for(int i=0;i<s.size();i++){
            int cnt=0;
            for(int j=i;j<s.size();j++){
                if(s[j]=='1'){
                    cnt++;
                }
                if(cnt==k){
                     string sub=s.substr(i,j-i+1);
                     if(j-i+1<mini){
                        mini=j-i+1;
                        st=sub;
                     }else if(j-i+1==mini && sub<st){
                        st=sub;
                     }

                }
 
            }
        }
        return st;
    }
};