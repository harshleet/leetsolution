class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        priority_queue<tuple<int,int,int>>pq;
        int ind=0;
        for(auto it: intervals){
            pq.push({it[0],it[1],ind});
            ind++;
        }
       vector<int>ans(intervals.size(),-1);
       vector<pair<int,int>>temp;
        while(!pq.empty()){
            int st=get<0>(pq.top());
            int en=get<1>(pq.top());
            int ind=get<2>(pq.top());
            pq.pop();
            int val=-1;
             temp.push_back({st,ind});
            for(int i=0;i<temp.size();i++){
                // cout<<"a"<<" "<<ind<<endl;
                if(temp[i].first>=en){
                    val=temp[i].second;
                    continue;
                }else{
                    break;
                }
            }
          
           ans[ind]=val;
        }
        return ans;
    }
};