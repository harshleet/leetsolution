class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
       vector<int>ps(n,-1);

       stack<int>st;

       for(int i=0;i<n;i++){
        if(st.empty() || arr[st.top()]<arr[i]){
            if(!st.empty()){
                ps[i]=st.top();
            }
            st.push(i);
        }else{
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ps[i]=st.top();
            }
            st.push(i);
        }
       } 
       vector<int>ns(n,n);

       stack<int>st1;

       for(int i=n-1;i>=0;i--){
        if(st1.empty() || arr[st1.top()]<=arr[i]){
            if(!st1.empty()){
                ns[i]=st1.top();
            }
            st1.push(i);
        }else{
            while(!st1.empty() && arr[st1.top()]>arr[i]){
                st1.pop();
            }
            if(!st1.empty()){
                ns[i]=st1.top();
            }
            st1.push(i);
        }
       } 

    //    for(int i=0;i<n;i++){
    //     cout<<ps[i]<<" "<<ns[i]<<" ";
    //    }
    //    cout<<endl;
        long long  ans=0;
          int mod=1e9+7;
        for(int i=0;i<n;i++){
            long long vl=(i-ps[i]);
            long long vl2=(ns[i]-i);
            ans=(ans+((vl*vl2)%mod)*arr[i])%mod;
        }
        return ans;

    }
};