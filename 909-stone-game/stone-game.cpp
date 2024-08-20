class Solution {
public:
    
    bool stoneGame(vector<int>& piles) {
        int maxi=0;
        int st=0,en=piles.size()-1,col=0,col2=0,t=0;
        while(st<=en){
            if(t==0){
                if(piles[st]>=piles[en]){
           
                    col+=piles[st];
                    st++;
                }else{
           
                    col+=piles[en];
                    en--;
                }
                t=1;
            }else{
                if(piles[st]<=piles[en]){
     
                    col2+=piles[st];
                    st++;
                }else{
                    col2+=piles[en];
                    en--;
                }
                t=0;
            }
            
        }
        
        return col-col2>=0;
    }
};