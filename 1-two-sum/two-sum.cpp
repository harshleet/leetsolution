class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
           v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int left=0;
        int right=nums.size()-1;
      
   while(left<right ){
      pair<int,int>p = v[left];
       pair<int,int>p2 = v[right];
        if(p.first+p2.first<target){
            left++;
        }
        else if(p.first+p2.first>target){
            right--;
        }
        else{
            break;
        }
     }
        pair<int,int>p = v[left];
       pair<int,int>p2 = v[right];
        vector<int>ve;
        ve.push_back(p.second);
        ve.push_back(p2.second);

        return ve;
    }
};