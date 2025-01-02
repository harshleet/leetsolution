class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>pre(words.size()+1,0);
        set<char>st={'a','e','i','o','u'};

       
        for(int i=1;i<=words.size();i++){
            if(st.find(words[i-1][0])!=st.end() && st.find(words[i-1].back())!=st.end()){
                pre[i]=pre[i-1]+1;
            }else{
                pre[i]=pre[i-1];
            }

        }
        vector<int>ans;
        for(auto it:queries){
            ans.push_back(pre[it[1]+1]-pre[it[0]]);
        }
        return ans;
    }
};