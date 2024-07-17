class Solution {
public:
// -1 -1  0 1 1 2
// f   s    t fo 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4){
            return {};
        }
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        for(int f=0;f<nums.size()-3;f++){
            for(int s=f+1;s<nums.size()-2;s++){
                int t=s+1;
                int fo=nums.size()-1;
                while(t<fo){
                    long long sum=nums[f];
                    sum+=nums[s];
                    sum+=nums[t];
                    sum+=nums[fo];
                    if(sum==target){
                        ans.insert({nums[f],nums[s],nums[t],nums[fo]});
                        t++;
                        fo--;
                    }else if(sum<target){
                       t++;
                    }else if(sum>target){
                        fo--;
                    }
                }
            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};