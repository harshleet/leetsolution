class Solution {
public:
    int helper(int ind,map<int,bool>&m,vector<int>&ds,int& n){
        if(ind==n+1){
            return 1;
        }
        int a=0;
        for(int i=1;i<=n;i++){
           if(m[i]==false && (i%ind==0 || ind%i==0)){
               m[i]=true;
               a+=helper(ind+1,m,ds,n);
               m[i]=false;
               
           }
        }
        return a;
    }
    int countArrangement(int n) {
        map<int,bool>m;
        vector<int>ds;
        
        int a=helper(1,m,ds,n);
        return a;
    }
};