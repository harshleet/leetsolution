class Solution {
public:
    double myPow(double x, int n) {
        double ans=(double)1;
        if(n<0){
            n=abs(n);
            x=1/x;
            while(n>0){
                if(n%2==1){
                    ans*=x;
                    n--;
                }
                x*=x;
                n/=2;
           }
           return ans;
        }
        while(n>0){
            if(n%2==1){
                ans*=x;
                n--;
            }
            x*=x;
            n/=2;
        }
        return ans;
    }
};