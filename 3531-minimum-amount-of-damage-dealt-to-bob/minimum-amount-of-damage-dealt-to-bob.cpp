class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        priority_queue<tuple<double,long long,long long>>pq;
        long long tsum=0;
        for(int i=0;i<damage.size();i++){
            long long val=ceil((health[i])/(double)power);
            pq.push({damage[i]/(double)val,damage[i],health[i]});
            tsum+=damage[i];
        }

        long long ans=0;

        while(!pq.empty()){
            long long d=get<1>(pq.top());
            long long h=get<2>(pq.top());
            pq.pop();
            long long vl=ceil((h)/(double)power)*tsum;
            ans+=vl;
            tsum-=d;
            
        }

        return ans;
    }
};