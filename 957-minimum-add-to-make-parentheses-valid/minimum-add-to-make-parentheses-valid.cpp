class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<pair<char,int>>st;
        int c=0;
        vector<pair<char,int>>temp;
        for(int i=0;i<s.size();i++){
            temp.push_back({s[i],i});
        }
        set<int>faul;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                 st.push(temp[i]);
            }else if(s[i]==')' && !st.empty() && st.top().first=='('){
                  st.pop();
            }else if(s[i]==')' && st.empty()){
                c++;
               
            }
 
        }
        while(!st.empty()){
            c++;
            st.pop();
        }
        return c;
        
    }
};