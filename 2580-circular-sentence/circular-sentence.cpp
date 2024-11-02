class Solution {
public:
    bool isCircularSentence(string sentence) {
        string temp="";
        char last='&';
        for(int i=0;i<sentence.size();i++){
            // cout<<i<<" ";
            if(sentence[i]==' '){
                // cout<<temp<<" ";
                last=temp.back();
                temp="";
            }else if(temp==""){
                // cout<<temp<<" ";
                if(sentence[i]!=last && last!='&'){
                    return false;
                }
                temp+=sentence[i];
            }else{
                // cout<<temp<<" ";
                temp+=sentence[i];
            }
        }
        if(sentence.back()!=sentence[0]){
                return false;
            }
        return true;
    }
};