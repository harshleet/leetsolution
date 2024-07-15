class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ng(nums2.size(),-1);
        stack<int>st;
        for(int i=0;i<nums2.size();i++){
            if(st.empty() || nums2[i]<nums2[st.top()]){
                st.push(i);
            }else{
                while(!st.empty() && nums2[i]>=nums2[st.top()]){
                    ng[st.top()]=nums2[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        map<int,int>mp;
        for(int i=0;i<ng.size();i++){
            mp[nums2[i]]=ng[i];
        }
        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};