class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int count=0;
        int j=0;
         map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]++;  
                 while(m['a']>=1 && m['b']>=1 && m['c']>=1){
                     count+=(n-i);
                     m[s[j]]--;
                     j++;
                     
                 }
                 
            
        }
        return count;
    }
};