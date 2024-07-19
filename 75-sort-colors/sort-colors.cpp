class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int temp=low;
        while(low<=high && temp<=high){
            cout<<low<<" "<<high<<" "<<temp<<endl;
            if(nums[low]==0){
                low++;
                temp=low;
            }else if(nums[high]==2){
                high--;
            }else if(nums[low]==2 && nums[high]==0){
                swap(nums[low],nums[high]);
                low++;
                high--;
                temp=low;
            }else if(nums[temp]==2){
                swap(nums[temp],nums[high]);
                high--;
            }else if(nums[temp]==0){
                swap(nums[temp],nums[low]);
                low++;
                temp=low;
            }else{
                temp++;
            }
        }

    }
};