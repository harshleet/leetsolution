class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<vector<int>>pre(n+1,vector<int>(32,0));

        for(int i=0;i<arr.size();i++){
            for(int j=0;j<=31;j++){
                if((1 & (arr[i]>>j))==1){
                    // cout<<i<<" "<<j<<endl;
                    pre[i+1][j]=1+pre[i][j];
                }else{
                    pre[i+1][j]=pre[i][j];
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int st=queries[i][0],end=queries[i][1];

            int val=0;
            for(int j=0;j<=31;j++){
                // cout<<pre[end+1][j]<<" "<<pre[st][j]<<endl;
                if((pre[end+1][j]-pre[st][j])%2==1){
                    val+=pow(2,j);
                }
            }
            cout<<endl;
            ans.push_back(val);
        }
        return ans;
    }
};