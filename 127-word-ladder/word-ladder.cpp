class Solution {
public:
    int diff(const std::string& str1, const std::string& str2) {
        int count = 0;
        for (size_t i = 0; i < str1.length(); ++i) {
            if (str1[i] != str2[i]) {
                ++count;
            }
        }
        return count;
    }

    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::queue<std::pair<std::string, int>> q;
        std::unordered_set<std::string> st(wordList.begin(), wordList.end());
        q.push({beginWord, 0});

        while (!q.empty()) {
            std::string node = q.front().first;
            int step = q.front().second;
            q.pop();

            if (node == endWord) {
                return step + 1;
            }

            for (auto it = st.begin(); it != st.end(); ) {
                if (diff(*it, node) == 1) {
                    q.push({*it, step + 1});
                    it = st.erase(it);
                } else {
                    ++it;
                }
            }
        }

        return 0;
    }
};