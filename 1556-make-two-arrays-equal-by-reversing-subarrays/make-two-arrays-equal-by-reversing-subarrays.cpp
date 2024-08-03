class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int>v(1001),v2(1001);
        for(int i=0;i<target.size();i++){
            v[target[i]]++;
            v2[arr[i]]++;
        }
        return v==v2;
    }
};