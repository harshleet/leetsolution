class Solution {
public:
   vector<int> helper(string ex,int size){
        if(ex.size()==0){
            return {};
        }
        vector<int>res;
        for(int i=0;i<ex.size();i++){
            if(ex[i]=='+' || ex[i]=='-' || ex[i]=='*'){
                vector<int>val1=helper(ex.substr(0,i),i);
                vector<int>val2=helper(ex.substr(i+1),size-i);
                for(int j=0;j<val1.size();j++){
                    for(int k=0;k<val2.size();k++){
                        if(ex[i]=='+'){
                           res.push_back(val1[j]+val2[k]);
                        }else if(ex[i]=='-'){
                            res.push_back(val1[j]-val2[k]);
                        }else{
                            res.push_back(val1[j]*val2[k]);
                        }

                    }
                }
                
            }
        }
        if(res.size()==0){
             res.push_back(stoi(ex));
        }
        return res;
        
        
    }
    vector<int> diffWaysToCompute(string expression) {
        return helper(expression,int(expression.size()));
    }
};