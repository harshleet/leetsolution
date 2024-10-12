class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>words(wordList.begin(),wordList.end());
        map<string,int>vis;

        queue<pair<string,int>>q;
        q.push({beginWord,0});
        vis[beginWord]=1;

        while(!q.empty()){
            string temp=q.front().first;
            int step=q.front().second;
            q.pop();

            if(temp==endWord){
                return step+1;
            }

            for(int i=0;i<temp.size();i++){
                for(char j='a';j<='z';j++){
                    string temp2=temp;
                    temp2[i]=j;
                    if(vis.find(temp2)==vis.end() && words.find(temp2)!=words.end()){
                        vis[temp2]=1;
                        q.push({temp2,step+1});
                    }
                }
            }
        }
        return 0;
    }
};