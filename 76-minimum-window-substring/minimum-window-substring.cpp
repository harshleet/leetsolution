class Solution {
public:
    string minWindow(string s, string t) {
       
        vector<int>m2(256,0);
       
       
        int j=0,mini=INT_MAX;
        int mind=-1;
        for(int i=0;i<t.size();i++){
            m2[t[i]]++;
          
        }
        int c=t.size();
       
        for(int i=0;i<s.size();i++){
                m2[s[i]]--;
                if(m2[s[i]]>=0){
                    c--;
                   
                }

            while(c==0 && j<=i ){
                if(mini>i-j+1){
                    mini=i-j+1;
                    mind=j;
                }
                        m2[s[j]]++;
                        if(m2[s[j]]>0){
                            c++;
                        }

                j++;
            }

        }
    if(mind==-1){
        return "";
    }
        return s.substr(mind,mini);
    }
};