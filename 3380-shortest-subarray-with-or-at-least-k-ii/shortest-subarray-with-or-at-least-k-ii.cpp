class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int>bits(32,0);
        int mini=INT_MAX;
        int st=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            string b=bitset<32>(nums[i]).to_string();
            for(int l=0;l<32;l++){
                if(b[l]=='1'){
                    bits[l]++;

                    if(bits[l]==1){
                        st|=(1<<(31-l));
                    }
                }
            }

            while(st>=k && j<=i){
                mini=min(mini,i-j+1);
                 string b1=bitset<32>(nums[j]).to_string();
                    for(int l=0;l<32;l++){
                        if(b1[l]=='1'){
                            bits[l]--;

                            if(bits[l]==0){
                                st&=(~(1<<(31-l)));
                            }
                        }
                    }
                    j++;
            }
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};