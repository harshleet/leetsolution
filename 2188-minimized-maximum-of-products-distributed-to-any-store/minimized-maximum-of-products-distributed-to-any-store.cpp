class Solution {
public:

    int isPos(vector<int>&quantities,int mid,int n){
        int c=0;
        for(int i=0;i<quantities.size();i++){
            c+=quantities[i]/mid;
            if(quantities[i]%mid!=0){
                c++;
            }
        }
        return c<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1,high=*max_element(quantities.begin(),quantities.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPos(quantities,mid,n)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};