class Solution {
public:
    string longestPalindrome(string s) {
        int maxi=0;
        string maxs="";
        for(int i=0;i<s.size();i++){
            int l=i,r=i;
            while(l>=0 && r<s.size()){
                if(s[l]==s[r]){
                    if(maxi<r-l+1){
                        maxi=r-l+1;
                        maxs=s.substr(l,r-l+1);
                    }
                    l--;
                    r++;
                }else{
                    break;
                }
                
            }
            l=i,r=i+1;
            while(l>=0 && r<s.size()){
                if(s[l]==s[r]){
                    if(maxi<r-l+1){
                        maxi=r-l+1;
                        maxs=s.substr(l,r-l+1);
                    }
                    l--;
                    r++;
                }else{
                    break;
                }
                
            }
            
        }
        return maxs;
    }
};