class Solution {
public:
    bool checkValidString(string s) {
        stack<char>st;
        stack<char>as;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]=='*'){
                as.push(i);
            }else{
                if(!st.empty()){
                    st.pop();
                }else if(!as.empty()){
                    as.pop();
                }else{
                    return false;
                }
            }
            
        }
      
        while(!as.empty() && !st.empty()){
              if(st.top()>as.top()){
                return false;
            }
            as.pop();
            st.pop();
        }
        return st.empty();
    }
};