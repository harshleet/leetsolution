class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>ans(numRows,""); 
        if(numRows<=1){
            return s;
        }
        int c=0;
        int j=0;
        for(int i=0;i<s.length();i++){
            if(j==numRows-1){
                  c=1;
              }
              else if (j==0){
                 c=0;
              }
               ans[j]+=s[i];
              if(c==0){
                  j++;
              }
              else{
                  j--;
              }
               
   
    }
    string a="";
    for(int i=0;i<ans.size();i++){
       a+=ans[i];
    }
    return a;
}
};