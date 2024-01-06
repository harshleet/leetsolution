class FindSumPairs {
public:
    unordered_map<int,int>m1;
    unordered_map<int,int>m2;

    vector<int>temp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
         for(int i=0;i<nums1.size();i++){
             m1[nums1[i]]++;
         } 
          for(int i=0;i<nums2.size();i++){
             m2[nums2[i]]++;
         } 
       
         temp2=nums2;
    }
    
    void add(int index, int val) {
        m2[temp2[index]]--;
        if(m2[temp2[index]]==0){
            m2.erase(temp2[index]);
        }
        temp2[index]+=val;
        m2[temp2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto it:m1){
            int a=it.second;
            if(m2.find(tot-it.first)!=m2.end()){
                ans+=m2[tot-it.first]*a;
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */