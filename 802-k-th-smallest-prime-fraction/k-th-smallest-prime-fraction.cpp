class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<tuple<double,int,int>>pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pq.push({-double(arr[i]/(double(arr[j]))),arr[i],arr[j]});
            }
        }
        vector<int> ans;
        int i=0;
        while(!pq.empty()&& i<k){
           
              ans={get<1>(pq.top()), get<2>(pq.top())};
              pq.pop();
              i++;
        }
        return ans;
    }
};