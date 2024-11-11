class Solution {
public:
    void fill_sieve(std::vector<bool>& sieve, int n) {
        sieve[0] = sieve[1] = false;
        for (int i = 2; i <= n; i++) {
            sieve[i] = true;
        }

        for (int i = 2; i * i <= n; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<bool>seive(1100);
        fill_sieve(seive,1100);
        vector<int>temp;
        for(int i=1;i<1100;i++){
            if(seive[i]==true){
                temp.push_back(i);
                
            }
        }
        for(int j=nums.size()-2;j>=0;j--){
            if(nums[j+1]<=nums[j]){
                int val=upper_bound(temp.begin(),temp.end(),nums[j]-nums[j+1])-temp.begin();
                cout<<val<<" ";
                if(val<temp.size()-1 && temp[val]<nums[j]){
                    nums[j]-=temp[val];
                    cout<<nums[j]<<" ";
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};