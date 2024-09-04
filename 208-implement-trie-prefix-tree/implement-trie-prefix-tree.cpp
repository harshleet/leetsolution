class TrieNode{
    public:
        bool isEnd;
        TrieNode* children[26];
};


class Trie {
public:
    TrieNode* getNode(){
        TrieNode* node=new TrieNode();
        node->isEnd=false;
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
    
    bool startsWith(string prefix) {
        TrieNode* crawl=root;

        for(int i=0;i<prefix.size();i++){
            if(crawl->children[int(prefix[i]-'a')]==NULL){
                return false;
            }
            crawl=crawl->children[int(prefix[i]-'a')];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */