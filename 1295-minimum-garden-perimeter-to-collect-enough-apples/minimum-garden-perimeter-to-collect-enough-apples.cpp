class Solution {
public:
    bool check(long long val,long long neededApples){
       
       long long  int ans=2*(val*(val+1))*(1 + 2*val);
        return ans>=neededApples;

    }
    long long minimumPerimeter(long long neededApples) {
        long long int low=1,high=1e5;
        long long ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,neededApples)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans*8;
    }
};