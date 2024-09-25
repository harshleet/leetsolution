class TrieNode{
    public:
        bool isEnd;
        TrieNode* children[26];
        int cnt;
};


class Trie {
public:
    TrieNode* getNode(){
        TrieNode* node=new TrieNode();
        node->isEnd=false;
        node->cnt=0;
        for(int i=0;i<26;i++){
            node->children[i]=NULL;
        }
        return node;
    }

    TrieNode* root;
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        TrieNode* crawl=root;

        for(int i=0;i<word.size();i++){
            if(crawl->children[int(word[i]-'a')]==NULL){
                crawl->children[int(word[i]-'a')]=getNode();
            }
            
            crawl=crawl->children[int(word[i]-'a')];
            crawl->cnt++;
        }
        crawl->isEnd=true;
    }
    bool search(string word) {
        TrieNode* crawl=root;

        for(int i=0;i<word.size();i++){
            if(crawl->children[int(word[i]-'a')]==NULL){
                return false;
            }
            crawl=crawl->children[int(word[i]-'a')];
        }
        return crawl->isEnd==true;
    }
    
    int startsWith(string prefix) {
        TrieNode* crawl=root;
        int val=0;
        for(int i=0;i<prefix.size();i++){
            if(crawl->children[int(prefix[i]-'a')]==NULL){
                return val;
            }
            // cout<<crawl->cnt<<" ";
            
            crawl=crawl->children[int(prefix[i]-'a')];
            val+=crawl->cnt;
            
        }
        return val;
    }
    
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* a=new Trie();
        for(int i=0;i<words.size();i++){
            a->insert(words[i]);
        }
        vector<int>ans;
        for(int i=0;i<words.size();i++){
            int val=a->startsWith(words[i]);
            ans.push_back(val);
            // cout<<endl;
        }
        return ans;
        //use of trie
    }
};