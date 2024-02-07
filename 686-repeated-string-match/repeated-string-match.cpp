class Solution {
public:


    int repeatedStringMatch(string a, string b) {
        if(a==b){
            return 1;
        }
        int n_appear=b.size()/a.size();
        string f="";
        for(int i=0;i<n_appear;i++){
            f+=a;
        }
        for(int i=0;i<=2;i++){
            if(f.find(b)!=std::string::npos){
                return n_appear+i;
            }
            f+=a;
        }
        return -1;
       
    }
};