class Solution {
public:
 bool helper(string fir,string sec,string n,bool found){
        if(n.size()==0 && found){
            return true;
        }
        // cout<<fir<<" "<<sec<<" "<<n<<endl;
        long long val1=stoll(fir);
        long long val2=stoll(sec);
        val1+=val2;
      
        string thi=to_string(val1);
        // cout<<thi<<endl;
      
        bool res=false;
        if(thi==n.substr(0,thi.size())){
              res=res|| helper(sec,thi,n.substr(thi.size()),true);
        }
        return res;
    }
    bool isAdditiveNumber(string n) {
        if(n.size() <= 2) return false;
        string fir="",sec="";
        bool res=false;
        for(int i=1;i<n.size();i++){
            fir=n.substr(0,i);
            if(fir.size()>1 && fir[0]=='0'){
                continue;
            }
            for(int j=1;j<=n.size()-i;j++){
                sec=n.substr(i,j);
                if(sec.size()>1 && sec[0]=='0'){
                    continue;
                }
                res=res||helper(fir,sec,n.substr(i+j),false);
            }
        }
        return res;
    }
};