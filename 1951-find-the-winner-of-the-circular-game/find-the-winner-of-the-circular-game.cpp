class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n==1){
            return 1;
        }
        queue<int>q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(!q.empty()){
            vector<int>store;
            int n=q.size();
            int vl=k;
            if(vl>q.size()){
                vl=(k%n);
                if(vl==0){
                    vl=n;
                }
                // cout<<vl<<" ";
            }
            for(int i=0;i<vl;i++){
                store.push_back(q.front());
                // cout<<q.front()<<" ";
                q.pop();
            }
            for(int i=0;i<store.size()-1;i++){
                q.push(store[i]);
            }
            if(q.size()==1){
                break;
            }
        }
        // cout<<q.size()<<endl;
        return q.front();
    }
};