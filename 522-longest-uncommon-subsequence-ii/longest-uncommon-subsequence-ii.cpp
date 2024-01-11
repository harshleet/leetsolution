class Solution {
public:
bool isSubsequence(string& str1, string& str2) {
    int i = 0, j = 0;

    while (i < str1.length() && j < str2.length()) {
        if (str1[i] == str2[j]) {
            ++i;
        }
        ++j;
    }

    return i == str1.length();
}
    int findLUSlength(vector<string>& strs) {
     
        int n=strs.size();
        vector<pair<int,string>>v(n);
        map<string, int>m;
        for(int i=0;i<n;i++){
             v[i]={strs[i].size(),strs[i]};
             m[strs[i]]++;
        }
        sort(v.begin(),v.end());
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                 bool a=isSubsequence(v[j].second,v[i].second);
                if(a==1){
                      m[v[j].second]++;
                }
                 
            }
        }
        for(int i=n-1;i>=0;i--){
            if(m[v[i].second]==1){
                return v[i].first;
            }
        }
        return -1;
        
    }
};