class Solution {
public:

        int lcm_f(int a,int b){
            return a*b/__gcd(a,b);
        }
    string fractionAddition(string expression) {
        set<char>sy={'-','+','*'};
        set<char>no={'0','1','2','3','4','5','6','7','8','9'};
        int t=0;
        vector<int>up;
        vector<int>lo;
        vector<char>mid;
         int n=expression.size();
        string temp="";
        for(int i=0;i<n;i++){
            if(temp=="" || no.find(expression[i])!=no.end() ){
                temp+=expression[i];
            }else if(sy.find(expression[i])!=sy.end()){
                if(temp!=""){
                   lo.push_back(stoi(temp));
                }
                temp="";
                mid.push_back(expression[i]);
            }else if(expression[i]=='/'){
                if(temp!=""){
                up.push_back(stoi(temp));
                }
                temp="";
            }
        }
        if(temp!=""){
              lo.push_back(stoi(temp));
          }
        if(up.size()==0){
              string ans="";
              ans+=to_string(up[0]/__gcd(up[0],lo[0]));
              ans+="/";
              ans+=to_string(lo[0]/__gcd(up[0],lo[0]));
              return ans;
        }
        int lcm=lo[0];
        for(int i=1;i<up.size();i++){
            lcm=lcm_f(lcm,lo[i]);
        }
        int com=up[0]*(lcm/lo[0]);
        for(int i=1;i<up.size();i++){
            if(mid[i-1]=='+'){
                com+=up[i]*(lcm/lo[i]);
            }else if(mid[i-1]=='-'){
                com-=up[i]*(lcm/lo[i]);
            }else if(mid[i-1]=='*'){
                com*=up[i]*(lcm/lo[i]);
            }
        }

            string ans="";
            int vl1=com/__gcd(com,lcm);
            int vl2=lcm/__gcd(com,lcm);
            if(vl1*vl2<0){
                ans+="-";
            }
              ans+=to_string(abs(vl1));
              ans+="/";
              ans+=to_string(abs(vl2));
              return ans;
    }
};