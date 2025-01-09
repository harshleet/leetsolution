class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(int i=0;i<words.size();i++){
            if(words[i].size()>=pref.size()){
                string temp=words[i].substr(0,int(pref.size()));
                if(temp==pref){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};