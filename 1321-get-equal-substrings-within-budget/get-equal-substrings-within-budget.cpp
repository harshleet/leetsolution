class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int j=0,maxi=0;
        for(int i=0;i<s.size();i++){
            int dif=abs(s[i]-t[i]);
            while(maxCost-dif<0 && j<=i){
                maxCost+=abs(s[j]-t[j]);
                j++;
            }
            maxCost-=dif;
            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};