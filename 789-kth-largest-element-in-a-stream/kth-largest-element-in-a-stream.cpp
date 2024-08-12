class KthLargest {
public:
    int kth;
    int prev=-1;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        for(int i=0;i<nums.size();i++){
            if(pq.size()<k){
                pq.push(nums[i]);
            }else if(pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
            
        }
    }
    
    int add(int val) {
     
       if(pq.size()<kth){
                pq.push(val);
            }else if(pq.top()<val){
                pq.pop();
                pq.push(val);
        }
        
        int vl=pq.top();
       
        return vl;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */