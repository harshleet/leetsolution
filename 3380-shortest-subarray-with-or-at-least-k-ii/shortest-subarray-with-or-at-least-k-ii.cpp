class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int cur=0,j=0,mini=INT_MAX;
        vector<int>fre(31,0);
        for(int i=0;i<nums.size();i++){
            cur|=nums[i];
            string temp=bitset<31>(nums[i]).to_string();
            for(int l=0;l<31;l++){
                if(temp[l]=='1'){
                    fre[l]++;
                }
            }
            while(cur>=k && j<=i){
                mini=min(mini,i-j+1);
                string t2=bitset<31>(nums[j]).to_string();
               
                for(int l=0;l<31;l++){
                    if(t2[l]=='1'){
                        fre[l]--;
                    }
                    if(fre[l]==0){
                        cur&=(~(1<<(30-l)));
                    }
                }
                j++;
            }
        }
        if(mini>=INT_MAX){
            return -1;
        }
        return mini;
    }
};