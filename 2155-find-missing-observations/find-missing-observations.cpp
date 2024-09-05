class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int tsum=mean*(rolls.size()+n);
        int mysum=tsum-accumulate(rolls.begin(),rolls.end(),0);
        if(mysum>6*n || mysum<n){
            return {};
        }
        vector<int>ans(n);
        int j=0;
        while(mysum!=0){
            ans[j]++;
            j=(j+1)%n;
            mysum--;
        }
        return ans;

    }
};