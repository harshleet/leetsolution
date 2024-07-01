class Solution {
public:
    int solve(vector<int>&temp){
        stack<int>st;
           int n=temp.size();
        vector<int>ps(temp.size(),-1);
        vector<int>ns(temp.size(),n);
     
        for(int i=0;i<n;i++){
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
        stack<int>st2;
        for(int i=n-1;i>=0;i--){
            if(st2.empty() || temp[st2.top()]<temp[i]){
                if(!st2.empty()){
                    ns[i]=st2.top();
                }
                st2.push(i);
            }else{
                while(!st2.empty() && temp[st2.top()]>=temp[i]){
                    st2.pop();
                }
                if(!st2.empty()){
                    ns[i]=st2.top();
                }
                st2.push(i);
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            // cout<<temp[i]<<" "<<ps[i]<<" "<<ns[i]<<" ";
           maxi=max(maxi,(ns[i]-ps[i]-1)*temp[i]);
        }
        cout<<endl;
        
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>temp(n,vector<int>(m,0));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && matrix[i][j]=='1'){
                    temp[i][j]=matrix[i][j]-'0';
                }else if(matrix[i][j]=='1'){
                    temp[i][j]=temp[i-1][j]+(matrix[i][j]-'0');
                }
            }
            maxi=max(maxi,solve(temp[i]));
        }
        return maxi;
    }
};