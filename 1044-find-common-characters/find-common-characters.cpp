class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>pre(26,0);
        for(int i=0;i<words[0].size();i++){
            pre[words[0][i]-'a']++;
        }
        for(int i=1;i<words.size();i++){
            vector<int>temp(26,0);
            for(int j=0;j<words[i].size();j++){
                temp[words[i][j]-'a']++;
            }
            for(int j=0;j<26;j++){
                temp[j]=min(temp[j],pre[j]);
            }
            pre=temp;

        }
        vector<string>ans;
        for(char j='a';j<='z';j++){
            for(int i=0;i<pre[j-'a'];i++){
                string t="";
                t+=j;
                ans.push_back(t);
            }
        }
        return ans;
    }
};