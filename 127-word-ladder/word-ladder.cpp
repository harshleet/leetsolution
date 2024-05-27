class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>word(wordList.begin(),wordList.end());
        map<string,int>vis;
        queue<pair<int,string>>q;
        q.push({0,beginWord});
        vis[beginWord]=1;
        while(!q.empty()){
            int dis=q.front().first;
            string node=q.front().second;
            q.pop();

            if(node==endWord){
                return dis+1;
            }
            string ori=node;
            for(int i=0;i<node.size();i++){
                for(char j='a';j<='z';j++){
                    ori[i]=j;
                   if(vis.find(ori)==vis.end() && word.find(ori)!=word.end()){
                      q.push({dis+1,ori});
                      vis[ori]=1;
                   }
                   ori=node;
                }
            }
        }
        return 0;
    }
};