class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<pair<int,int>>psum(n+1);
        vector<pair<int,int>>nsum(n+1);
        int sum=0,cnt=0;
        for(int i=0;i<n;i++){
            psum[i+1]={sum,cnt};
            if(boxes[i]=='1'){
                sum+=i;
                cnt++;
            }
            
        }
        sum=0,cnt=0;
        for(int i=n-1;i>=0;i--){
            nsum[i+1]={sum,cnt};
             if(boxes[i]=='1'){
                sum+=i;
                cnt++;
            }
        }
        // for(int i=0;i<=n;i++){
        //     pair<int,int>p=psum[i];
        //     pair<int,int>n=nsum[i];
        //     cout<<p.first<<" "<<p.second<<" "<<n.first<<" "<<n.second<<endl;
        // }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            pair<int,int>p=psum[i+1];
            pair<int,int>n=nsum[i+1];
            ans[i]=abs(p.first-p.second*i)+abs(n.first-n.second*i);
        }
        return ans;

    }
};