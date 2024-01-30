class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        set<string>sym={"+","-","*","/"};
        stack<int>s;
        for(int i=0;i<tokens.size();i++){
            if(sym.find(tokens[i])==sym.end()){
                s.push(stoi(tokens[i]));
            }else{
                int a,b;
                if(!s.empty()){
                   a=s.top();
                   s.pop();
                   b=s.top();
                   s.pop();
                }
                if(tokens[i]=="+"){
                    s.push(a+b);
                }else if(tokens[i]=="-"){
                    s.push(b-a);
                }else if(tokens[i]=="*"){
                    s.push(a*b);
                }else if(tokens[i]=="/"){
                    s.push(b/a);
                }
            }

        }
        return s.top();
    }
};