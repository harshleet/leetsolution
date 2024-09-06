class TrieNode{
    public:
        bool isEnd;
        TrieNode* children[26];
        set<string>phone;
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
            crawl->phone.insert(word);
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
    
    set<string> startsWith(string prefix) {
        TrieNode* crawl=root;

        for(int i=0;i<prefix.size();i++){
            if(crawl->children[int(prefix[i]-'a')]==NULL){
                return {};
            }
            crawl=crawl->children[int(prefix[i]-'a')];
        }
        return crawl->phone;
    }
    
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* a=new Trie();
        for(int i=0;i<products.size();i++){
            a->insert(products[i]);
        }
        vector<vector<string>>ans;
        for(int i=0;i<searchWord.size();i++){
            set<string>temp=a->startsWith(searchWord.substr(0,i+1));
            if(temp.size()<=3){
                ans.push_back(vector<string>(temp.begin(),temp.end()));
            }else{
                ans.push_back(vector<string>(temp.begin(), next(temp.begin(), 3)));
            }
            
        }
        return ans;
    }
};