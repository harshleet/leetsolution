class Solution {
public:
    void helper(int ind, string ds, set<string>& ans, string& s,
                set<char>& num) {
        if (ind >= s.size()) {
            ans.insert(ds);
            return;
        }
        ds.push_back(tolower(s[ind]));
        helper(ind + 1, ds,ans, s,num);
        ds.pop_back();
        if (num.find(s[ind]) == num.end()) {
            ds.push_back(toupper(s[ind]));
             helper(ind + 1, ds,ans,s,num);
            ds.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        set<char> num = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        string ds = "";
        set<string> ans;
        helper(0, ds, ans, s, num);
        return vector<string>(ans.begin(),ans.end());
    }
};