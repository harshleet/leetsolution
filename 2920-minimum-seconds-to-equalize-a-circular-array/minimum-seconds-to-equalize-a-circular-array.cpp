class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        map<int,vector<int>>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m[nums[i]].push_back(0);
                m[nums[i]].push_back(i);
            }else{
                m[nums[i]].push_back(i);
            }
        }
       
        int mini=INT_MAX;
        for(auto it:m){
            it.second.push_back(nums.size());
             int maxi=INT_MIN;
            for(int j=0;j<it.second.size()-1;j++){
               maxi=max(maxi,it.second[j+1]-it.second[j]);
            }
            // int a=nums.size()-1-it.second.back();
            
            // maxi=max(maxi,a);
            // cout<<maxi<<" ";
            mini=min(mini,maxi);
        }
       return ceil(mini/2);
    }
};