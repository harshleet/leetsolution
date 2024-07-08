class Solution {
public:
    vector<int>nums;
    Solution(vector<int>& nums) {
        this->nums=nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        int n=nums.size();
        vector<int>temp(n);
        map<int,int>vis;
        
        for(int i=0;i<n;i++){
            int vl=rand()%n;
            while(vis.find(vl)!=vis.end()){
                vl=rand()%n;
            }
            temp[vl]=nums[i];
            vis[vl]=1;
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */