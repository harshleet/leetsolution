class Solution {
public:
int mod= 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<pair<long long,long long>>pq;
        for(int i=0;i<n;i++){
            pq.push({efficiency[i],speed[i]});
        }

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>temp;
        long long  mini=LLONG_MAX,sum=0;
        long long maxi=0;
        while(!pq.empty()){
            pair<long long,long long>p=pq.top();
            pq.pop();
            if(temp.size()<k){
                temp.push({p.second,p.first});
                mini=min(mini,p.first);
                sum=(sum+p.second);
                maxi=max(maxi,sum*mini);
            }else{
                 temp.push({p.second,p.first});
                 long long tval=temp.top().first;
                 temp.pop();
                 sum=(sum+-tval+p.second);
                 mini=min(mini,p.first);
                maxi=max(maxi,sum*mini);
            }
        }
        return maxi%mod;
    }
};