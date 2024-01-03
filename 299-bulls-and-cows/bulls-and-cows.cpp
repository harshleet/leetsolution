class Solution {
public:
    string getHint(string secret, string guess) {
        int c=0;
        int w=0;
        map<int,int>m;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                c++;
            }else{
                m[secret[i]]++;
            }
        }
        for(int i=0;i<secret.size();i++){
            if(secret[i]!=guess[i] && m[guess[i]]!=0){
               m[guess[i]]--;
               w++;
            }
        }
        string s="";
        s+= to_string(c);
        s+='A';
        s+= to_string(w); 
        s+='B';
        return s;
    }
};