class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        deque<int> q{1, 2, 3, 4, 5, 6, 7, 8, 9};
        while (--n > 0) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int p = q.front();
                q.pop_front();
              
                    if ((p % 10) - k>=0) {
                        q.push_back(p * 10 + (p % 10) - k);
                    }
                    if ((p % 10) +k<=9) {
                        q.push_back(p * 10 + (p % 10) +k);
                    }
                
            }
        }
        set<int>a=set<int>{q.begin(), q.end()};
        vector<int>(a.begin(),a.end());
        return         vector<int>(a.begin(),a.end());
    }
};
