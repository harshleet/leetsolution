class Solution {
public:
    int countSubstrings(string s) {
         int cnt=0;
        for(int i=0;i<s.size();i++){
            int l=i,r=i;
            while(l>=0 && r<s.size()){
                if(s[l]==s[r]){
                    cnt++;
                    l--;
                    r++;
                }else{
                    break;
                }
                
            }
            l=i,r=i+1;
            while(l>=0 && r<s.size()){
                if(s[l]==s[r]){
                   cnt++;
                    l--;
                    r++;
                }else{
                    break;
                }
                
            }
            
        }
        return cnt;
    }
};