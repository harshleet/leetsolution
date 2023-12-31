
class Solution {
public:
    bool possible(string& s, int mid) {
        vector<int>mp(26,0);
        vector<int>m(26,0);
       int uni=0;
        int j=0;
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]-'a']++;
            if(mp[s[i]-'a']==1){
                uni++;
            }
            if(i-j+1==mid){
                if (uni == 1) {
                    m[s[j]-'a']++;
                    if (m[s[j]-'a'] >= 3) {
                        return true;
                    }
                }
                mp[s[j]-'a']--;
                if(mp[s[j]-'a']==0){
                    uni--;
                }
                j++;
            }
            
        }
        
        return false;
    }

    int maximumLength(string s) {
        int low = 1, high = s.size()-2;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(s, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};