class Solution {
public:
    bool judgeSquareSum(int c) {
        if(ceil(sqrt(c))==sqrt(c)){
            return true;
        }
        for(int i=1;i<=sqrt(c);i++){
            if( ceil(sqrt(c-pow(i,2)))==sqrt(c-pow(i,2))){
                return true;
            }
        }
        return false;
    }
};