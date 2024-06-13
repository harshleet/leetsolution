class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ng(nums2.size(),-1);
        map<int,int>m;
        stack<int>st;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]]=i;
            if(st.empty() || nums2[st.top()]>nums2[i]){
                st.push(i);
            }else{
                while(!st.empty() && nums2[st.top()]<nums2[i]){
                    ng[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
        }
        vector<int>ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            int val=ng[m[nums1[i]]];
            if(val!=-1){
                ans[i]=nums2[val];
            }

        }
        return ans;
    }
};