class Solution {
public:
    int helper(int n,int len,int copylen,int op){
        if(len>n){
            return 1e8;
        }
        if(n==len){
            return 0;
        }
        int copy=1e9;
        if(op!=1){
           copy=1+helper(n,len,len,1);
        }
        int paste=1e9;
        if(copylen!=0){
            paste=1+helper(n,copylen+len,copylen,2);
        }
        return min(copy,paste);
    }
    int minSteps(int n) {
       
        return helper(n,1,0,0);
    }
};