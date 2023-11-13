class Solution {
public:
    int numTilePossibilities(string tiles) {
        map<char, int> m;
        for (char ch : tiles) {
            m[ch]++;
        }

        int result = 0;
        backtrack(m, result);
        return result;
    }

    void backtrack(map<char, int>& m, int& result) {
        for (auto& kvp : m) {
            if (kvp.second > 0) {
                result++; // Increment result for each unique combination

                kvp.second--; // Choose the current character
                backtrack(m, result);
                kvp.second++; // Backtrack to explore other possibilities
            }
        }
    }
};
