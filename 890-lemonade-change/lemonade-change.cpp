class Solution {
public:
    bool lemonadeChange(vector<int>& nums) {
        int f=0,t=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==5){
                f++;
            }else if(nums[i]==10){
                t++;
                if(f>0){
                    f--;
                }else{
                    return false;
                }
            }else if(nums[i]==20){
                if(f>0 && t>0){
                    f--;
                    t--;
                }else if(f>2){
                    f-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};