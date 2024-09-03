class Solution {
public:
    int getLucky(string s, int k) {
        string ans="";
        for(int i=0;i<s.size();i++){
            ans+=to_string(int(s[i]-'a')+1);
        }
        for(int j=0;j<k;j++){
            // cout<<ans<<" ";
            int val=0;
            for(int i=0;i<ans.size();i++){
                val+=int(ans[i]-'0');
            }
            ans=to_string(val);
        }
        return stoi(ans);
    }
};