class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //find previos smaller and next smaller
        //now just do it
        int n=heights.size();
        vector<int>ps(n,-1);
        vector<int>ns(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty() || heights[st.top()]<heights[i]){
                if(!st.empty()){
                    ps[i]=st.top();
                }
                st.push(i);
            }else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ps[i]=st.top();
                }
                st.push(i);
            }
        }
         while (!st.empty()) {
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            if(st.empty() || heights[st.top()]<heights[i]){
                if(!st.empty()){
                    ns[i]=st.top();
                }
                st.push(i);
            }else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ns[i]=st.top();
                }
                st.push(i);
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<ps[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<ns[i]<<" ";
        // }
        int maxi=0;
        for(int i=0;i<n;i++){
            int lo=ps[i],hi=ns[i];
            if(hi==-1){
                hi=n;
            }
            maxi=max(maxi,(hi-lo-1)*heights[i]);
        }
        return maxi;
    }
};