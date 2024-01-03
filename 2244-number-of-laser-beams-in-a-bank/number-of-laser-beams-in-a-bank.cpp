class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>val;
        for(int i=0;i<bank.size();i++){
            int c=0;
             for(int j=0;j<bank[i].size();j++){
                 if(bank[i][j]=='1'){
                     c++;
                 }
             }
             if(c!=0){
                 val.push_back(c);
             }
        }
        if(val.empty()){
            return 0;
        }
        int ans=0;
        for(int i=1;i<val.size();i++){
            ans+=val[i]*val[i-1];
        }
        return ans;

    }
};