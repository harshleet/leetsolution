class cmp{
    public:
    bool operator()(pair<char,int>&a, pair<char,int>&b)
    {
        if (a.first > b.first) {
            return true;
        }
        else if (a.first == b.first
                 && a.second < b.second) {
            return true;
        }
 
        return false;
    }
};

class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmp>pq;
        set<int>st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                 char t=pq.top().first;
                 st.insert(pq.top().second);
                 pq.pop();
            }else{
                pq.push({s[i],i});
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(st.find(i)==st.end() && s[i]!='*'){
                ans+=s[i];
            }
        }
        return ans;
    }
};