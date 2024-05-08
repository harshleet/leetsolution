class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        int n=score.size();
        vector<int>rank(score.begin(),score.end());
        sort(rank.begin(),rank.end());
        vector<string>medals={"Gold Medal","Silver Medal","Bronze Medal"};
        map<int,string>m;
        for(int i=0;i<min(3,n);i++){
            m[rank[rank.size()-1-i]]=medals[i];
        }
        if(min(3,n)==3){
        for(int i=0;i<rank.size()-3;i++){
            m[rank[i]]=to_string(rank.size()-i);
        }}
        vector<string>ans(n);
        for(int i=0;i<n;i++){
            if(m.find(score[i])!=m.end()){
                ans[i]=m[score[i]];
            }
        }
        return ans;
    }
};