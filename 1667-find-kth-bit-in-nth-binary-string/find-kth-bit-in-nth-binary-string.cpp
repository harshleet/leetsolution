class Solution {
public:
    char findKthBit(int n, int k) {
        int nu=pow(2,n)-1;
        if(k==1){
            return '0';
        }
       
        if(k==nu/2){
            return '1'; 
        }
        if(k<nu/2){
            return findKthBit(n-1,k);
        }
        if(findKthBit(n-1,nu-k+1)=='1'){
            return '0';
        }
        
            return '1';
        
    }
};