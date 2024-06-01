class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int mini=INT_MAX,cnt=0,j=0;
        string st="";
        for(int i=0;i<s.size();i++){
                if(s[i]=='1'){
                    cnt++;
                }
                while((cnt>k || s[j]=='0') && j<=i){
                    
                     if(s[j]=='1'){
                        cnt--;
                    }
                    j++;

                }
                if(cnt==k){
                       string sub=s.substr(j,i-j+1);
                    if(i-j+1<mini){
                        mini=i-j+1;
                        st=sub;
                     }else if(i-j+1==mini && sub<st){
                        st=sub;
                     }
                }
        }
        return st;
    }
};