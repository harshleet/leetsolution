class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int>arr;
        for(int j=0;j<nums.size();j++){
            if(nums[j]>0){
                arr.push_back(nums[j]);
            }
        }
        
        int i = 0;
        while (i < arr.size()) {
            int correct = arr[i] - 1;
            if (correct<arr.size() && arr[i] != arr[correct]) {
                swap(arr[i], arr[correct]);
            } else {
                i++;
            }
        }
        for(int j=0;j<arr.size();j++){
           
            if(arr[j]!=j+1){
                return j+1;
            }
        }
        return arr.size()+1;
    }
};