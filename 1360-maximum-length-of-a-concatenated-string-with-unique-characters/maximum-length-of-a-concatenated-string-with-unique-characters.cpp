class Solution {
public:
    bool check(const string& s) {
        unordered_set<char> uniqueChars;
        for (char c : s) {
            if (uniqueChars.count(c) > 0) {
                return false;
            }
            uniqueChars.insert(c);
        }
        return true;
    }

    int helper(int ind, vector<string>& arr, string current) {
        if (ind == arr.size()) {
            if (check(current)) {
                return current.size();
            }
            return 0;
        }
   
        int withoutCurrentString = helper(ind + 1, arr, current);
        int withCurrentString = 0;

        if (check(current + arr[ind])) {
            withCurrentString = helper(ind + 1, arr, current + arr[ind]);
        }

        return max(withoutCurrentString, withCurrentString);
    }

    int maxLength(vector<string>& arr) {
	 vector<int>dp(arr.size(),-1);
        return helper(0, arr, "");
    }
};
