class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k){
            return "0"; 
        }
        set<int>removed;
        stack<int>st;
        for(int i=0;i<num.size();i++){
            if(st.empty() || (num[st.top()]-'0')<=(num[i]-'0')){
                st.push(i);
            }else{
                while(!st.empty() && k>0 && (num[st.top()]-'0')>(num[i]-'0')){
                    removed.insert(st.top());
                    k--;
                    st.pop();
                }
                st.push(i);
            }
        }
        // cout<<st.size()<<" "<<k<<endl;
        while(!st.empty() && k>0){
            // cout<<st.top()<<endl;
           removed.insert(st.top());
                    k--;
                    st.pop();
        }
        // cout<<removed.size()<<" ";
        string ans="";
        for(int i=0;i<num.size();i++){
            
            if(removed.find(i)==removed.end()){
                if(ans=="" && num[i]=='0'){
                    continue;
                }
                ans+=num[i];
            }
        }
        if(ans==""){
            return "0";
        }
        return ans;
    }
};