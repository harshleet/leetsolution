class Solution {
public:
    bool solve(vector<char>&values,char op){
        // cout<<values.size()<<" "<<op<<endl;
        // for(auto it:values){
        //     cout<<it<<" ";
        // }
        if(op=='!'){
            if(values[0]=='t'){
                return false;
            }
            return true;
        }
        if(op=='&'){
            bool fl=false;
            for(auto it:values){
                if(it=='f'){
                    fl=true;
                }
            }
            if(fl==true){
                return false;
            }
            return true;
        }
        if(op=='|'){
            bool fl=false;
            for(auto it:values){
                if(it=='t'){
                    fl=true;
                }
            }
            if(fl==true){
                return true;
            }
            return false;
        }
        return false;
    }
    bool parseBoolExpr(string expression) {
        stack<char>st;

        for(int i=0;i<expression.size();i++){
            if(expression[i]==','){
                continue;
            }else if(expression[i]==')'){
                vector<char>values;
                while(st.top()!='('){
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();

                char op=st.top();
                st.pop();
                bool val=solve(values,op);
                if(val==true){
                    st.push('t');
                }else{
                    st.push('f');
                }
                
            }else{
                st.push(expression[i]);
            }
        }
        if(st.top()=='t'){
            return true;
        }
        return false;

    }
};