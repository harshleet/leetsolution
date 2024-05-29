class Solution {
public:
    int numSteps(string s) {
        string temp = s;
        int step = 0;
        while (s.size() != 1) {
            if (s.back() == '0') {
                s = s.substr(0, s.size() - 1);
            } else if (s.back() == '1') {
                bool f = false;
                for (int j = s.size() - 1; j >= 0; j--) {
                    if (s[j] == '1') {
                        s[j] = '0';
                    
                    } else {
                        s[j] = '1';
                            f = true;
                        break;
                    }
                }
                if (f == false) {
                    string temp2 = "1";
                    temp2 += s;
                    s = temp2;
                }
            }
            // cout << s << " ";
            step++;
        }
        return step;
    }
};