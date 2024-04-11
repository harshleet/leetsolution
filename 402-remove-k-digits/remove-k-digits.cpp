class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        for(int i=0;i<num.size();i++){
         
           while(!s.empty() && s.top()>num[i] && k>0){
             s.pop();
             k--;
           }
           s.push(num[i]);
        }
        string ans="";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        
        if(k>0){
            ans=ans.substr(k);
        }
        
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans.size()>1 && ans[i]=='0'){
           i++;
        }
        ans=ans.substr(i);
        if(ans==""){
            return "0";
        }
        return ans;
        
    }
};