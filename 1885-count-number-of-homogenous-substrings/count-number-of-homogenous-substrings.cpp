class Solution {
public:
int mod=1e9+7;
  
    int countHomogenous(string s) {
        long long  int n=s.size();
        int j=0;
           long long ans=0;
        string temp="";
      
        int i;
        for(i=0;i<n;i++){
            if( i==0||s[i-1]==s[i]){
                 continue;
            }
             long long int len=i-j;
             cout<<len<<" ";
             long long int tot=((len*(len+1))/2)%mod;
             ans=(ans+tot)%mod;
             j=i;
        }
        long long  int len=i-j;
         long long int tot=(len*(len+1))/2;
        ans=(ans+tot)%mod;


        return ans;
    }
};