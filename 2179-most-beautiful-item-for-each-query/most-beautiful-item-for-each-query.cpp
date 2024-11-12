class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n=items.size();
        vector<int>pre(n,0);
        pre[0]=items[0][1];
        vector<int>temp(n);
        temp[0]=items[0][0];
        for(int i=1;i<n;i++){
            pre[i]=max(items[i][1],pre[i-1]);
            temp[i]=items[i][0];
        }
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int ind=lower_bound(temp.begin(),temp.end(),queries[i]+1)-temp.begin();
            if(ind>0){
                ans[i]=pre[ind-1];
            }else{
                ans[i]=0;
            }
        }
        return ans;
    }
};