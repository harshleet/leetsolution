class Solution {
public:
    int helper(int ind, vector<int>& score, map<char, int>& m,
               vector<string>& words) {
        if (ind >= words.size()) {
            return 0;
        }
        int nt = helper(ind + 1, score, m, words);
        int t = 0, cnt = 0;
        map<char, int> temp = m;
        bool f=false;
        for (int i = 0; i < words[ind].size(); i++) {
            if (temp[words[ind][i]] > 0) {
                temp[words[ind][i]]--;
                cnt+=score[int(words[ind][i]-'a')];
            }else{
                f=true;
            }
        }
        if(f==false){
            t=cnt+helper(ind+1,score,temp,words);
        }
        return max(t,nt);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        map<char, int> m;
        for (int i = 0; i < letters.size(); i++) {
            m[letters[i]]++;
        }
        return helper(0, score, m, words);
    }
};