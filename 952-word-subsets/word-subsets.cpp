class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<vector<int>>mp1(words1.size(),vector<int>(26,0));
        vector<vector<int>>mp2(words2.size(),vector<int>(26,0));

        vector<int>uni(26,0);
        

        for(int i=0;i<words2.size();i++){
            for(int j=0;j<words2[i].size();j++){
                mp2[i][int(words2[i][j]-'a')]++;
            }
            for(int j=0;j<26;j++){
                uni[j]=max(uni[j],mp2[i][j]);
            }
        }
        for(int i=0;i<words1.size();i++){
            for(int j=0;j<words1[i].size();j++){
                mp1[i][int(words1[i][j]-'a')]++;
            }
            int cnt=0;
            for(int j=0;j<26;j++){
                if(uni[j]<=mp1[i][j]){
                    cnt++;
                }
            }
            if(cnt==26){
                ans.push_back(words1[i]);
            }
        }

      
        return ans;
    }
};