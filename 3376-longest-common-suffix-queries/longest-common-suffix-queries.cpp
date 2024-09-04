class TrieNode{
    public:
        bool isEnd;
        int index;
        TrieNode* children[26];
};


class Trie {
public:
    TrieNode* getNode(int ind){

        TrieNode* node=new TrieNode();
        node->isEnd=false;
        for(int i=0;i<26;i++){
            node->children[i]=NULL;
        }
        node->index=ind;
        
        return node;
    }

    TrieNode* root;
    Trie(vector<string>& wordsContainer) {
        root=getNode(0);
        for(int i=0;i<wordsContainer.size();i++){
            if(wordsContainer[i].size()<wordsContainer[root->index].size()){
                root->index=i;
            }
        }
    }
    
    void insert(string word,int ind,vector<string>& wordsContainer) {
        // cout<<word<<" "<<ind<<endl;
        TrieNode* crawl=root;

        for(int i=0;i<word.size();i++){
            if(crawl->children[int(word[i]-'a')]==NULL){
                crawl->children[int(word[i]-'a')]=getNode(ind);
            }else if(wordsContainer[crawl->children[int(word[i]-'a')]->index].size()>wordsContainer[ind].size()){
                crawl->children[int(word[i]-'a')]->index=ind;
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
    
    int startsWith(string prefix,map<int,int>&mp) {
        TrieNode* crawl=root;
        for(int i=0;i<prefix.size();i++){
            if(crawl->children[int(prefix[i]-'a')]==NULL){
                 return crawl->index;
            }
            crawl=crawl->children[int(prefix[i]-'a')];
        }
        return crawl->index;
        // int mini = INT_MAX, minii = -1;
        // for (int i = 0; i < crawl->index.size(); i++) {
        //     if (mp[crawl->index[i]] < mini) {
        //         mini = mp[crawl->index[i]];
        //         minii = crawl->index[i];
        //     }
        // }
        // return minii;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* a=new Trie(wordsContainer);
        int i=0;
        map<int,int>mp;
        for(auto it:wordsContainer){
           
            reverse(it.begin(),it.end());
            a->insert(it,i,wordsContainer);
            mp[i]=it.size();
            i++;
        }
        
        vector<int>ans;
        for(auto it:wordsQuery){
            reverse(it.begin(),it.end());
            int val=a->startsWith(it,mp);
            ans.push_back(val);
        }
        return ans;

    }
};