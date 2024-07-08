class Solution {
public:
    int findTheWinner(int n, int k) {
        
        queue<int>q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }

        while(!q.empty()){
            int sz=q.size();
            if(sz==1){
                break;
            }
            vector<int>temp;
            int t=k;
            if(sz<t){
                t%=sz;
                if(t==0){
                    t=sz;
                }
            }
            for(int i=0;i<t;i++){
                temp.push_back(q.front());
                q.pop();
            }
            // cout<<temp[t-1]<<endl;
            for(int i=0;i<t-1;i++){
                q.push(temp[i]);
            }
        }
        return q.front();
    }
};