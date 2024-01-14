class Solution {
public:
     void prefix(vector<int>&lps,string &pat){
         int n=pat.length();
         lps[0]=0;
         int len=0;
         int i=1;

         while(i<n){
             if(pat[i]==pat[len]){
                 len++;
                 lps[i]=len;
                 i++;
             }else{
                 if(len==0){
                     lps[i]=0;
                     i++;
                 }else{
                     len=lps[len-1];
                 }
             }
         }
     }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        //kmp implementation int this
        if(s.length()<a.length() ||s.length()<b.length()  ){
             return {};
         }
         vector<int>occ;
         vector<int>lps(b.length());
         prefix(lps,b);
         int i=0,j=0;
         while(i<s.size()){
             if(s[i]==b[j]){
                 i++;
                 j++;
             }
             if(j==b.size()){
                 occ.push_back(i-j);
                 j=lps[j-1];
             }else if(i<s.size() && s[i]!=b[j]){
                 if(j!=0){
                     j=lps[j-1];
                 }else{
                     i++;
                 }
             }
         }
         vector<int>occ2;
         vector<int>lps2(a.length());
         prefix(lps2,a);
         i=0,j=0;
         while(i<s.size()){
             if(s[i]==a[j]){
                 i++;
                 j++;
             }
             if(j==a.size()){
                 occ2.push_back(i-j);
                 j=lps2[j-1];
             }else if(i<s.size() && s[i]!=a[j]){
                 if(j!=0){
                     j=lps2[j-1];
                 }else{
                     i++;
                 }
             }
         }
      vector<int>an;
         for (int i = 0; i <occ2.size(); i++) {
         
                auto it = lower_bound(occ.begin(), occ.end(), occ2[i]-k);
               auto it2 = upper_bound(occ.begin(), occ.end(), occ2[i]+k);
                if (distance(it, it2)>0) {
                    an.push_back(occ2[i]);
                }
        }
         
        return an;
    }
};