class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int tm=0,tg=0,tp=0,m=0,p=0,g=0;
        for(int i=0;i<garbage.size();i++){
            for(int j=0;j<garbage[i].size();j++){
               if(garbage[i][j]=='M'){
                    m+=tm+1;
                    tm=0;
               }
               if(garbage[i][j]=='P'){
                   p+=tp+1;
                    tp=0;
               }
               if(garbage[i][j]=='G'){
                   g+=tg+1;
                    tg=0;
               }
            }
            if(i<travel.size()) {
            tm+=travel[i];
            tg+=travel[i];
            tp+=travel[i];}
        }
        return m+p+g;
    }
};