class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long>s;
        priority_queue<long long,vector<long long>,greater<long long>>q;
        int cnt=0;
        q.push(1);

        while(!q.empty()){
                long long node=q.top();
                q.pop();
                cnt++;
                // cout<<node<<" "<<cnt<<endl;
                if(cnt==n){
                    return node;
                }
                if(s.find(node*2)==s.end()){
                    s.insert(node*2);
                    q.push(node*2);
                }
                if(s.find(node*3)==s.end()){
                     s.insert(node*3);
                    q.push(node*3);
                }
                if(s.find(node*5)==s.end()){
                     s.insert(node*5);
                    q.push(node*5);
                }
        }
        return -1;
    }
};