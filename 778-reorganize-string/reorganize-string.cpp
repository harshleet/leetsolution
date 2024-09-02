class Solution {
public:
    string reorganizeString(string s) {
        vector<int>fre(26,0);
        for(int i=0;i<s.size();i++){
            fre[s[i]-'a']++;
            if(fre[s[i]-'a']>ceil(s.size()/2.0)){
                return "";
            }
        }
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++){
            if(fre[i]>0)
               pq.push({fre[i],char(i+'a')});
        }

        string ans="";
        while(!pq.empty()){
            if(pq.top().first==1){
                break;
            }
            vector<pair<int,char>>temp;
            ans+=pq.top().second;
            temp.push_back(pq.top());
            pq.pop();

            if(!pq.empty()){
                ans+=pq.top().second;
                temp.push_back(pq.top());
                pq.pop();
            }
            for(int i=0;i<temp.size();i++){
                if(temp[i].first>1){
                    pq.push({temp[i].first-1,temp[i].second});
                }
            }
        }

        while(!pq.empty()){
            ans+=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};