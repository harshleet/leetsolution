class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        map<int,pair<int,int>>m;
        //so their eight ways the queen can attack
        int rk=king[0],ck=king[1];
       for(int i=0;i<queens.size();i++){
           int rq=queens[i][0];
           int cq=queens[i][1];
           if(cq==ck){
               if(rk>rq){
                   if(m.find(1)==m.end()|| m[1].first<rq){
                      m[1]={rq,cq};
                   }
               }else{
                    if(m.find(5)==m.end()|| m[5].first>rq){
                      m[5]={rq,cq};
                   }
               }
           }else if(rq==rk){
               if(ck>cq){
                   if(m.find(3)==m.end()|| m[3].second<cq){
                      m[3]={rq,cq};
                   }
               }else{
                    if(m.find(7)==m.end()|| m[7].second>cq){
                      m[7]={rq,cq};
                   }
               }
           }else if(cq+rq==ck+rk){
               if(rk>rq){
                   if(m.find(2)==m.end()|| m[2].first<rq){
                      m[2]={rq,cq};
                   }
               }else{
                    if(m.find(6)==m.end()|| m[6].first>rq){
                      m[6]={rq,cq};
                   }
               }
           }else if(8-(cq-rq)==8-(ck-rk)){
               if(rk>rq){
                   if(m.find(8)==m.end()|| m[8].first<rq){
                      m[8]={rq,cq};
                   }
               }else{
                    if(m.find(4)==m.end()|| m[4].first>rq){
                      m[4]={rq,cq};
                   }
               }
           }
       }
       vector<vector<int>>v;
       for(auto it:m){
            v.push_back({it.second.first,it.second.second});
       }
       return v;


    }
};