class Solution {
public:
    int minOperations(vector<string>& logs) {
        int c=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i][0]=='.' && logs[i][1]=='.' && c>0){
                c--;
            }else if(logs[i][0]=='.' && logs[i][1]=='/'){
               continue;
            }else if(logs[i][0]!='.'){
                c++;
            }
        }
        return c;
    }
};