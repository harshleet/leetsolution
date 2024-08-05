class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            if(it.second>ceil(s.size()/2.0)){
                return "";
            }
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
            // cout<<"a"<<endl;
             vector<pair<int,char>>temp;
             temp.push_back(pq.top());
             ans+=pq.top().second;
            //   cout<<pq.top().second<<endl;
            pq.pop();
           
            for(int i=0;i<1;i++){
                if(!pq.empty()){
                    ans+=pq.top().second;
                    temp.push_back(pq.top());
                    //  cout<<pq.top().second<<endl;
                    pq.pop();
                }
            }

            for(int i=0;i<temp.size();i++){
                if(temp[i].first>1){

                    pq.push({temp[i].first-1,temp[i].second});
                }
            }
        }
        return ans;
    }
};