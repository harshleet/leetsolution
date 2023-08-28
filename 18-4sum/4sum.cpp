class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         set<vector<int>>ans;
        
        sort(nums.begin(),nums.end());

       for(int vlow=0;vlow<nums.size();vlow++){
        for(int low=vlow+1;low<nums.size();low++){
            int middle=low+1;
             int high=nums.size()-1;
            while( middle<high){
                long long int vlval=nums[vlow];
                long long int lval=nums[low];
               long long int hval=nums[high];
               long long int mval=nums[middle];
        
                    if(lval+mval+hval+vlval>target){
                        high--;
                    }else if(lval+mval+hval+vlval<target){
                        middle++;
                    }
                
            
                else{
                        ans.insert({int(lval),int(mval),int(hval),int(vlval)});
                        middle++;
                        high--;
                    }
            }
        }}
        vector<vector<int>>an(ans.begin(),ans.end());
        return an;
    }
};