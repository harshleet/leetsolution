class Solution {
public:
    int nthUglyNumber(int n) {
       set<long long>st;

       st.insert(1);
       int cnt=1;
       long long val=1;
       while(!st.empty() && cnt<=n){
           val=*st.begin();
           st.erase(val);

           cnt++;
           if(cnt==n+1){
             break;
           }
           st.insert(val*2);
           st.insert(val*3);
           st.insert(val*5);
       }
        return val;
    }
};