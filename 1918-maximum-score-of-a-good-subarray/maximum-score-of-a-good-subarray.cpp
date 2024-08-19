class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ps(n,-1);
        vector<int>ns(n,n);

        stack<int>st;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || nums[st.top()]<nums[i]){
                if(!st.empty()){
                    ps[i]=st.top();
                }
                st.push(i);
            }else{
                while(!st.empty() && nums[st.top()]>=nums[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ps[i]=st.top();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(st.empty() || nums[st.top()]<nums[i]){
                if(!st.empty()){
                    ns[i]=st.top();
                }
                st.push(i);
            }else{
                while(!st.empty() && nums[st.top()]>=nums[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ns[i]=st.top();
                }
                st.push(i);
            }
        }
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(k>ps[i] && k<ns[i]){
            maxi=max(maxi,(ns[i]-ps[i]-1)*nums[i]);}
            // cout<<ps[i]<<" ";
        }
        // cout<<endl;
        // for(int i=0;i<nums.size();i++){
        //     cout<<ns[i]<<" ";
        // }
        return maxi;
    }
};