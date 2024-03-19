class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:m){
            pq.push({it.second,it.first});
        }
         string ans="";
        while(!pq.empty()){
            
            vector<pair<int,char>>left;
             ans+=pq.top().second;
             left.push_back(pq.top());
             pq.pop();
             if(pq.size()==0){
                 break;
             }else{
                ans+=pq.top().second;
                left.push_back(pq.top());
                pq.pop();
             }
              for(int i=0;i<left.size();i++){
                if(left[i].first>1){
                    pq.push({left[i].first-1,left[i].second});
                }
               
             }
        }
        if(ans.size()!=s.size()){
            return "";
        }
        return ans;
    }
};