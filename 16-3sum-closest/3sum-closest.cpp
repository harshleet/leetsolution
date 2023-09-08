class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        int no=INT_MAX;
        for(int low=0;low<nums.size()-2;low++){
            int middle= low+1;
            int high= nums.size()-1;
            while(middle<high){

                int lval=nums[low];
                int hval=nums[high];
                int mval=nums[middle];
                int sum = lval + hval + mval;
                int diff = std::abs(sum - target);

                if(diff<mini){
                    mini=diff;
                    no=sum;
                }
                 if(lval+mval+hval>target){
                        high--;
                 }else {
                        middle++;
                }
            }
        }
        return no;
    }
};