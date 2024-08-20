class Solution {
public:

    int helper(vector<int>&temp){
        int m=temp.size();
        vector<int>ps(m,-1);
        vector<int>ns(m,m);

        stack<int>st;

        for(int i=0;i<m;i++){
            if(st.empty() || temp[st.top()]<temp[i]){
                
                if(!st.empty()){
                    ps[i]=st.top();
                }
                st.push(i);
            }else{

                while(!st.empty() && temp[st.top()]>=temp[i]){
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

        for(int i=m-1;i>=0;i--){
            if(st.empty() || temp[st.top()]<temp[i]){
                
                if(!st.empty()){
                    ns[i]=st.top();
                }st.push(i);
            }else{

                while(!st.empty() && temp[st.top()]>=temp[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ns[i]=st.top();
                }
                st.push(i);
            }
        }

        int ans=0;
        for(int i=0;i<m;i++){
            if(temp[i]!=0){
                // cout<<ns[i]<<" "<<ps[i]<<" "<<i<<endl;
                ans=max(ans,(ns[i]-ps[i]-1)*temp[i]);
            }
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix[0].size();
        vector<int>temp(m,0);

        int maxi=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    temp[j]++;
                }else{
                    temp[j]=0;
                }
            }
            maxi=max(maxi,helper(temp));
        }
        return maxi;
    }
};