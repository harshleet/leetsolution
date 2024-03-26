class Solution {
public:

    int firstMissingPositive(vector<int>& nums) {
       map<int,int>m;
       int maxi=INT_MIN;
       for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
        maxi=max(maxi,nums[i]);
       }
       for(int i=1;i<=max(1,maxi);i++){
        if(m.find(i)==m.end()){
            return i;
        }
       }
       return maxi+1;
    }
};