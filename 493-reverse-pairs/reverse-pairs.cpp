class Solution {
public:

   void merge(int low,int mid,int high,vector<int>&arr){
        vector<long long int>temp;
        long long int i=low,j=mid+1;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        while(j <=high){
            temp.push_back(arr[j]);
            j++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }

    long long countPair(int low,int mid,int high,vector<int>&arr){
         long long int c=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            long long val=arr[i];
            long long val2=arr[right];
            val2*=2;
            while(right<=high && val>val2){
                right++;
                val2=arr[right];
                val2*=2;
            }
            c+=(right-mid-1);
          
        }
        return c;
    }
    long long int mergesort(int low,int high,vector<int>&arr){
        if(low==high){
            return 0;
        }
        int mid=(low+high)/2;
        long long int a=mergesort(low,mid,arr);
        long long int b=mergesort(mid+1,high,arr);
        long long c=countPair(low,mid,high,arr);
        merge(low,mid,high,arr);
        return a+b+c;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(0,nums.size()-1,nums);
    }
};