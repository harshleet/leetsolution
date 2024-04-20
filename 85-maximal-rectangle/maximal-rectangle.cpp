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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>temp(m,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    temp[j]=0;
                }else{
                    temp[j]+=1;
                }
            }
            maxi=max(maxi,largestRectangleArea(temp));
        }
        return maxi;
    }
};