class Solution {
public:
    string reorganizeString(string s) {
        //same as task scheduler
        priority_queue<pair<int,char>>pq;
        map<char,int>m;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            maxi=max(maxi,m[s[i]]);
        }
        if(maxi>ceil(s.size()/(double)2)){
            return "";
        }
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        string ans="";

        while(!pq.empty()){
            if(pq.top().first==1){
                while(!pq.empty()){
                    ans+=pq.top().second;
                    pq.pop();
                }
                return ans;
            }
            vector<pair<int,char>>temp;
            temp.push_back(pq.top());
 
            ans+=pq.top().second;
            pq.pop();
            if(!pq.empty()){
               temp.push_back(pq.top());
               ans+=pq.top().second;
               pq.pop();
            }
            for(int i=0;i<temp.size();i++){
                // cout<<temp[i].first<<" "<<ans<<endl;
                if(temp[i].first>1){
                   pq.push({temp[i].first-1,temp[i].second});
                }
            }
        }
        return ans;
    }
};