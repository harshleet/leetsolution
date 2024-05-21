class Solution {
public:
    void helper(int op, int cl, int n, string& ds, vector<string>& ans) {
        if (op == n) {
            int prev=cl;
            while (cl < op) {
                ds += ')';
                cl++;
            }
            ans.push_back(ds);
            while (prev<cl) {
                ds.pop_back();
                cl--;
            }
            return;
        }

        ds.push_back('(');
        helper(op + 1, cl, n, ds, ans);
        ds.pop_back();
        if (op > cl) {
            ds.push_back(')');
            helper(op, cl + 1, n, ds, ans);
            ds.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string ds;
        vector<string> ans;
        helper(0, 0, n, ds, ans);
        return ans;
    }
};