class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        int cnt=0,maxi=0;
        m[0]=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt++;
            }else if(nums[i]==1){
                cnt--;
            }
            if(m.find(cnt)!=m.end()){
                 maxi=max(maxi,i+1-m[cnt]);
            }else{
                m[cnt]=i+1;
            }
        }
       return maxi;
    }
};