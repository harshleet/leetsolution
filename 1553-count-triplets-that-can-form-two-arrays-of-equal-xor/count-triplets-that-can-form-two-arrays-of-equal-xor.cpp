class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans=0,n=arr.size();
        vector<int>pre(n+1);
        pre[0]=0;
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]^arr[i];
            // cout<<pre[i+1]<<endl;
        }
        for(int i=0;i<arr.size();i++){
            // txor^=arr[i];
            for(int k=i+1;k<arr.size();k++){
                int x=pre[i]^pre[k+1];
                if(x==0){
                    ans+=k-i;
                }
            }
            
        }
        return ans;
    }
};