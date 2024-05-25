class Solution {
public:
    void helper(int ind, string ds, vector<string>& ans, string s,
                set<string>& dict) {
        if (ind >= s.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 1; i <= s.size() - ind; i++) {
            string sub = s.substr(ind, i);
            string temp = ds;
            if (dict.find(sub) != dict.end()) {
                if (ds == "") {
                    ds += sub;
                } else {
                    ds += " " + sub;
                }
                helper(ind+i,ds,ans,s,dict);
            }
            ds=temp;
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        set<string> dict(wordDict.begin(), wordDict.end());
        helper(0, "", ans, s, dict);
        return ans;
    }
};