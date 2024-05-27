class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int j=0,ans=0,rep=0,mini=INT_MAX;
        map<int,int>m;
        for(int i=0;i<cards.size();i++){
             
                if(m.find(cards[i])!=m.end()){
                    mini=min(mini,i-m[cards[i]]+1);
                }
               m[cards[i]]=i;
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};