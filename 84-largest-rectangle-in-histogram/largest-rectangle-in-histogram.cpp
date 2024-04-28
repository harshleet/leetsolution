class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>preS(n,-1);
        vector<int>nextS(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                nextS[st.top()]=i;
                st.pop();
            }
            if(!st.empty()){
                preS[i]=st.top();
            }
            st.push(i);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            int sel=heights[i];
            
            if(preS[i]!=-1){
                sel+=heights[i]*(i-preS[i]-1);
            }else if(preS[i]==-1){
                 sel+=heights[i]*(i);
            }
            if(nextS[i]!=-1){
                sel+=heights[i]*(nextS[i]-i-1);
            }else if(nextS[i]==-1){
                 sel+=heights[i]*(n-i-1);
            }
            maxi=max(maxi,sel);
        }
        return maxi;
    }
};