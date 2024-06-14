class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        vector<int>ps(n,-1);
        vector<int>ns(n,n);

        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty() || arr[st.top()]<=arr[i]){
                if(!st.empty()){
                    ps[i]=st.top();
                }
                st.push(i);
            }else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ps[i]=st.top();
                }
                st.push(i);
            }
        }
        stack<int>st1; 
        for(int i=n-1;i>=0;i--){
            if(st1.empty() || arr[st1.top()]<arr[i]){
                if(!st1.empty()){
                    ns[i]=st1.top();
                }
                st1.push(i);
            }else{
                while(!st1.empty() && arr[st1.top()]>=arr[i]){
                    st1.pop();
                }
                if(!st1.empty()){
                    ns[i]=st1.top();
                }
                st1.push(i);
            }
        }
        vector<int>pg(n,-1);
        vector<int>ng(n,n);

        stack<int>st2;
        for(int i=0;i<n;i++){
            if(st2.empty() || arr[st2.top()]>=arr[i]){
                st2.push(i);
            }else{
                while(!st2.empty() && arr[st2.top()]<arr[i]){
                    ng[st2.top()]=i;
                    st2.pop();
                }
                
                st2.push(i);
            }
        }
        stack<int>st3; 
        for(int i=n-1;i>=0;i--){
            if(st3.empty() || arr[st3.top()]>arr[i]){
                st3.push(i);
            }else{
                while(!st3.empty() && arr[st3.top()]<=arr[i]){
                    pg[st3.top()]=i;
                    st3.pop();
                }
                st3.push(i);
            }
        }
        long long ans=0;
        for(int i = 0; i < n; i++) {
            
            long long val = (i - pg[i]);
            val = (val * (ng[i] - i));
            val = (val * arr[i]);
            ans = (ans +val);
        }
        cout<<ans<<" ";
        for(int i = 0; i < n; i++) {
            
            long long val = (i - ps[i]);
            val = (val * (ns[i] - i));
            val = (val * arr[i]);
            ans = (ans - val);
        }

        return ans;
    }
};