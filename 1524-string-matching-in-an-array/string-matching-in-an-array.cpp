class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        map<string,int>mp;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                for(int k=1;k<=words[i].size()-j;k++){
                    string temp=words[i].substr(j,k);
                    if(temp!=words[i]){
                        mp[temp]++;
                    }
                }
            }
        }
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            if(mp.find(words[i])!=mp.end()){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};