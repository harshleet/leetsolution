class Solution {
public:
    void merge(int l,int mid,int h,vector<int>&nums){
        int st=l;
        vector<int>temp;
        int low=mid+1;

        while(l<=mid && low<=h){
            if(nums[l]<=nums[low]){
                temp.push_back(nums[l]);
                l++;
            }else{
                temp.push_back(nums[low]);
                low++;
            }
        }
        while(l<=mid){
            temp.push_back(nums[l]);
                l++;
        }
        while(low<=h){
            temp.push_back(nums[low]);
                low++;
        }
        for(int i=0;i<temp.size();i++){
            nums[st+i]=temp[i];
        }
    }
    void helper(int l,int h,vector<int>&nums){
        if(l>=h){
            return;
        }
        int mid=(l+h)/2;
        helper(l,mid,nums);
        helper(mid+1,h,nums);
        merge(l,mid,h,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        helper(0,nums.size()-1,nums);
        return nums;
    }
};