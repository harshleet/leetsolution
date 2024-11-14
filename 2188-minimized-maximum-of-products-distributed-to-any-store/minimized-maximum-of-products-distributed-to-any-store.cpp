class Solution {
public:
    bool isPos(int mid,int n, vector<int>& quantities){
        int val=0;
        for(int i=0;i<quantities.size();i++){
            val+=ceil(quantities[i]/(double)mid);
        }
        return val<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1,h=*max_element(quantities.begin(),quantities.end());

        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;

            if(isPos(mid,n,quantities)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};