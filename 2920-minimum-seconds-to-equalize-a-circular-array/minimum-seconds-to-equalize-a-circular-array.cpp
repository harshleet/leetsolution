class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        map<int,vector<int>>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
           
                m[nums[i]].push_back(i);
            
        }
       
        int mini=INT_MAX;
        for(auto it:m){
             int maxi=INT_MIN;
            for(int j=0;j<it.second.size()-1;j++){
               maxi=max(maxi,it.second[j+1]-it.second[j]);
            }
            mini=min(mini,maxi);
        }
       return  mini/2;
    }
};