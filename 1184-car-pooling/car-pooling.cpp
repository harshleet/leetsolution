class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //naive solution

        int n=trips.size();
       map<int,int>m;
     
       for(int i=0;i<n;i++){
           m[trips[i][1]]+=trips[i][0];
           m[trips[i][2]]-=trips[i][0];
       }
        //two optioon eityher move on timestamp or either on only important point
        int cap=capacity;
        for(auto it:m){
            cap-=it.second;
           if(cap<0){
               return false;
           }
        }
       

        return true;


    }
};