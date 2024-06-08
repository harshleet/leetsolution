typedef long long ll;
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n=arr.size();
        vector<long long >ans(n,0);
        map<ll,ll>m;
        map<ll,ll>cnt;
        for(int i=0;i<n;i++){
            if(cnt[arr[i]]!=0){
                ans[i]+=abs(cnt[arr[i]]*i-m[arr[i]]);
            }
            cnt[arr[i]]++;
            m[arr[i]]+=i;
        }
         map<ll,ll>m1;
        map<ll,ll>cnt1;
        for(int i=n-1;i>=0;i--){
            if(cnt1[arr[i]]!=0){
                ans[i]+=abs(cnt1[arr[i]]*i-m1[arr[i]]);
            }
            cnt1[arr[i]]++;
            m1[arr[i]]+=i;
        }

        return ans;
    }
};