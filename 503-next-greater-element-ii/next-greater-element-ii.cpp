class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        nums.insert(nums.end(),nums.begin(),nums.end());
        vector<int>ng(nums.size(),-1);

        stack<int>st;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || nums[st.top()]>=nums[i]){
                st.push(i);
            }else{
                while(!st.empty() && nums[st.top()]<nums[i]){
                    ng[st.top()]=nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        return vector<int>(ng.begin(),ng.begin()+(ng.size()/2));
    }
};