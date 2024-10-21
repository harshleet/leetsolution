class Solution {
public:
    int helper(int ind,map<string,int>&mp,string &s){
        if(ind>=s.size()){
            return 0;
        }
        int maxi=0;
        for(int i=1;i<=s.size()-ind;i++){
            string temp=s.substr(ind,i);
            if(mp.find(temp)==mp.end()){
                mp[temp]++;
                maxi=max(maxi,1+helper(ind+i,mp,s));
                mp.erase(temp);
            }
        }
        return maxi;
    }
    int maxUniqueSplit(string s) {
        //easy
        //break krna hai then check wherether present or not 
        int ans=0;
        map<string,int>mp;
        return helper(0,mp,s);
    }
};