class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        reverse(piles.begin(),piles.end());
        int j=piles.size()-1;
        int get=0;
        for(int i=0;i<j;i+=2){
            get+=piles[i+1];
            j--;
        }
        return get;
    }
};