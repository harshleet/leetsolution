class Solution {
public:
    bool check(string& a ,string &b){
        int val=0;
        for(int i=1;i<=b.size();i++){
            string c=b.substr(0,i);
            if(c==a){
                val++;
                break;
            }
        }
        for(int i=0;i<b.size();i++){
            string c=b.substr(i);
            if(c==a){
                val++;
                break;
            }
        }
        return val==2;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int c=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(check(words[i],words[j])){
                    c++;
                }
            }
        }
        return c;
    }
};