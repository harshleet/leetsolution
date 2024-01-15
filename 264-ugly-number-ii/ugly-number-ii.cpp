class Solution {
public:
   
    int nthUglyNumber(int n) {
       set<long long int>s;
       long long int cnt=0;
       s.insert(1);
       long long int val=1;
       while(!s.empty() && n > 0){
            val=*(s.begin());
            s.erase(val);
           n--;
           if (n == 0) {
                break;
            }
            s.insert(val*2);
            
            s.insert(val*3);
            
            s.insert(val*5);
            
       }
       return val;
    }
};