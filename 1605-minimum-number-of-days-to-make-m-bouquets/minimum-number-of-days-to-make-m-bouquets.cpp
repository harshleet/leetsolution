class Solution {
public:
    bool isPos(int mid,vector<int>& bloomDay, int m, int k){
        cout<<mid<<endl;
        int c=0;

        int temp=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                temp++;
            }else{
                temp=0;
            }
            if(temp==k){
                c++;
                temp=0;
            }
        }
        return c>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=*min_element(bloomDay.begin(),bloomDay.end()),h=*max_element(bloomDay.begin(),bloomDay.end());

        cout<<l<<" "<<h<<endl;
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(isPos(mid,bloomDay,m,k)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};