class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
          int n = nums[0].size();
          set<string>s(nums.begin(),nums.end());
        for (int i = 0; i < (1 << n); i++) {
            bitset<32> b(i);
            string st= b.to_string().substr(32-n) ;
            if(s.find(st)==s.end()){
                return st;
            }
     
 
        }
            return nums[0];
    }
};