class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>temp=heights;
        int ans=0;
        sort(temp.begin(),temp.end());
        int i=0;
        for(auto it:heights){
            if(it!=temp[i]){
                ans++;
            }
            i++;
        }
        return ans;
    }
};