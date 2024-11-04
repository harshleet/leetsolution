class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int f=1;
        for(int i=1;i<word.size();i++){
            if(word[i]!=word[i-1]){
               ans+=to_string(f);
               ans+=word[i-1];
               f=1; 
            }else if(word[i]==word[i-1]){
                if(f==9){
                    ans+=to_string(f);
                    ans+=word[i-1];
                    f=0; 
                }
               f++;
            }
        }
        if(f>0){
            ans+=to_string(f);
            ans+=word.back();
        }
        
        return ans;
    }
};