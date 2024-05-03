class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v;
        vector<int> v1;
        string t1 = "";
        string t2 = "";
        for (int i = 0; i < version1.size(); i++) {
            if (version1[i] == '.') {
                if (t1.size() != 0) {
                    // cout << t1 << " ";
                    int vl = stoi(t1);
                    v.push_back(vl);
                    t1 = "";
                }
            } else {
                t1 += version1[i];
            }
        }
        if (t1.size() != 0) {
        //    cout << t1 << " ";
            int vl = stoi(t1);
            v.push_back(vl);
        }
        for (int i = 0; i < version2.size(); i++) {
            if (version2[i] == '.') {
                if (t2.size() != 0) {
                    // cout << t2 << " ";
                    int vl = stoi(t2);
                    v1.push_back(vl);
                    t2 = "";
                }
            } else {
                t2 += version2[i];
            }
        }
        if (t2.size() != 0) {
        //    cout << t2 << " ";
            int vl = stoi(t2);
            v1.push_back(vl);
            t2 = "";
        }
        for (int i = 0; i < min(v.size(), v1.size()); i++) {
            cout<<v1[i]<<" "<<v[i]<<" ";
            if (v1[i] > v[i]) {
                return -1;
            }
            if (v1[i] < v[i]) {
                return 1;
            }
        }

        if (v.size() > min(v.size(), v1.size())) {
            for (int i = min(v.size(), v1.size()); i < v.size(); i++) {
                if (0 < v[i]) {
                    return 1;
                }
            }
        }
        if (v1.size() > min(v.size(), v1.size())) {
            for (int i = min(v.size(), v1.size()); i < v1.size(); i++) {
                if (0 < v1[i]) {
                    return -1;
                }
            }
        }
        return 0;
    }
};