class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        map<int,int>m;
        // vector<vector<int>>v(n);
        // for(int i=0;i<n;i++){
        //     v[i]={trips[i][1],trips[i][2],trips[i][0]};
        // }
        // sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            for(int j=trips[i][1];j<trips[i][2];j++){
                m[j]+=trips[i][0];
                if(m[j]>capacity){
                    return false;
                }
            }
           
        }
        // int prvs=v[0][0],prve=v[0][1],prvp=v[0][2];
        // pair<int,int>maxi={prvp,prve};
        // int p=prvp;
        // for(int i=1;i<n;i++){
        //     if(v[i][0]<prve){
        //        p+=v[i][2];
        //    }else if(v[i][0]<maxi.second){
        //        maxi.first+=v[i][2];
        //    }else{
        //         p=v[i][2];
        //    }
        //    if(maxi.first<=p){
        //        maxi.first=p;
        //        maxi.second=min(maxi.second,v[i][1]);
        //    }
        //    if(maxi.first>capacity){
        //        return false;
        //    }
           
        // }

        return true;


    }
};