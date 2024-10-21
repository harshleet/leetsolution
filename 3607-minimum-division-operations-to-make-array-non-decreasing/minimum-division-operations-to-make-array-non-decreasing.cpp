class Solution {
public:
    int findValue(int val1,int val2){
        for(int i=2;i<=sqrt(val1);i++){
            if(val1%i==0){
                if(val1/i<=val2){
                    return val1/i;
                }
            }
        }
        for(int i=2;i<=sqrt(val1);i++){
            if(val1%i==0){
                if((val1/(val1/i))<=val2){
                    return (val1/(val1/i));
                }
            }
        }
        return -1;
    }
    int minOperations(vector<int>& nums) {
        int pre=nums.size()-1;
        int op=0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                continue;
            }else{
                int val=findValue(nums[i],nums[i+1]);
                if(val==-1){
                    return -1;
                }
                nums[i]=val;
                op++;
            }
        }
        return op;
    }
};