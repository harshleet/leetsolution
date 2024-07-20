class Solution {
public:
    int beautySum(string s) {
        //try all substring
        int ans=0; 
        for(int i=0;i<s.size();i++){
            vector<int>frq(26,0);
           
            // string st="";
            for(int j=i;j<s.size();j++){
                frq[s[j]-'a']++;
                // st+=s[j];
                int maxi=0,mini=INT_MAX;
                for(int k=0;k<26;k++){
                    if(frq[k]!=0){
                      maxi=max(maxi,frq[k]);
                     mini=min(mini,frq[k]);
                    }             
                }
                // cout<<st<<" ";
               
                ans+=maxi-mini;
            }
        }
        return ans;
    }

};