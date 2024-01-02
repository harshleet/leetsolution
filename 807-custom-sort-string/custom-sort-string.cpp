class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>m;
        for(int i=0;i<s.size();i++){
                m[s[i]]++;
        }
        map<char,int>m2;
        string ans="";
        for(int i=0;i<order.size();i++){
               if(m.find(order[i])!=m.end()){{
                   for(int j=0;j<m[order[i]];j++)
                        ans+=order[i];
                        m2[order[i]]++;}
               }
        }
        for(int i=0;i<s.size();i++){
               if(m2.find(s[i])==m2.end()){
                 ans+=s[i];
               }
        }
        return ans;
    }
};