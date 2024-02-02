class Solution {
public:
int hammingWeight(int n) {
        int c=0;
        while(n>0){
           if(n&1){
               c++;
           }
           n>>=1;
        }
        return c;
    }
    int totalHammingDistance(vector<int>& nums) {
        int toc=0;
        
        for(int i=0;i<32;i++){      
            int c=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]&1){
                   c++;
                }
                nums[j]>>=1;
            }
            toc+=(c)*(nums.size()-c);
           
        }
        return toc;
    }
};