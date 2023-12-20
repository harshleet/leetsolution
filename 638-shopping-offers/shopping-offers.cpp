class Solution {
public:
     int pc(vector<int>&a,vector<int>&b){
         int ans=0;
        for(int i=0;i<a.size();i++){
            ans+=a[i]*b[i];
        }
        return ans;
     }
    int helper(int ind,vector<int>& price, vector<vector<int>>& special, vector<int>& needs, map<int,int>&m){
        //new method for the dp array u can use the map
        if(ind>=special.size()){
            return pc(needs,price);
        }
        int key=ind;
        for(int i=0;i<needs.size();i++){
            key+=key*10+needs[i];
        }
        if(m.find(key)!=m.end()){
            return m[key];
        }
        int ntake=helper(ind+1,price,special,needs,m);
        int take=INT_MAX;
        vector<int>temp=needs;
        int fl=0;
        for(int i=0;i<special[ind].size()-1;i++){
            if(temp[i]>=special[ind][i]){
                temp[i]-=special[ind][i];
            }else{
                 fl=1;
            }
        }
        if(fl==0){
             take=special[ind].back()+helper(ind,price,special,temp,m);
        }
        return m[key]= min(take,ntake);

    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<int,int>m;
        return helper(0,price,special,needs,m);
    }
};