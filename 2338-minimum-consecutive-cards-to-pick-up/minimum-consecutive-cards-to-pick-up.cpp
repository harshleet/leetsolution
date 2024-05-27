class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int j=0,ans=0,rep=0,mini=INT_MAX;
        map<int,int>m;
        for(int i=0;i<cards.size();i++){
                m[cards[i]]++;
                if(m[cards[i]]>1){
                    rep++;
                }
                while(rep>0 && j<=i){
                    mini=min(mini,i-j+1);
                    m[cards[j]]--;
                    if(m[cards[j]]==1){
                        rep--;
                    }
                    j++;
                }
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};