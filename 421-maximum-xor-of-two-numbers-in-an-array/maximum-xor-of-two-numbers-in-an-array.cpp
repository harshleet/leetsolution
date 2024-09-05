class TrieNode{
    public:
    TrieNode* left;
    TrieNode* right;

    TrieNode(){
        left=NULL;
        right=NULL;
    }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root=new TrieNode();
        
        for(int i=0;i<nums.size();i++){
            TrieNode* crawl=root;
            for(int j=31;j>=0;j--){
                int bit=(nums[i] & (1<<j));
                if(bit==0){
                    if(crawl->left==NULL){
                        crawl->left=new TrieNode();
                    }
                    crawl=crawl->left;
                }else{
                    
                    if(crawl->right==NULL){
                        crawl->right=new TrieNode();
                    }
                    crawl=crawl->right;
                }
            }
        }

        int maxi=0;
        for(int i=0;i<nums.size();i++){
            TrieNode* crawl=root;
            int val=0;
            for(int j=31;j>=0;j--){
                int bit=(nums[i] & (1<<j));
                if(bit==0){
                    if(crawl->right==NULL){
                         crawl=crawl->left;
                    }else{
                        val+=pow(2,j);
                        crawl=crawl->right;
                    }
                    
                }else{
                    if(crawl->left==NULL){
                        crawl=crawl->right;
                    }else{
                        val+=pow(2,j);
                       crawl=crawl->left;
                    }
                    
                    
                }
            }
            maxi=max(maxi,val);
        }
        return maxi;
    }
};