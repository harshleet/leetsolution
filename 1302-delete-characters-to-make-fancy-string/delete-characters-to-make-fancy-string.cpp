class Solution {
public:
    string makeFancyString(string s) {
        int f=1;
        char c=s[0];
        string temp="";
       for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            f++;
        }else{
            if(f==1){
                temp+=c;
            }else{
                temp+=c;
                temp+=c;
            }
            c=s[i];
            f=1;
        }
     
       }
       if(f==1){
                temp+=c;
            }else{
                temp+=c;
                temp+=c;
            }
           
       return temp; 
    }
};