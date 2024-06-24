class Solution {
public:
    int minOperations(vector<int>& nums) {
           int i=0;
            int n=nums.size();
            int op=0;
         while(i<n-2){
                 int f=nums[i],s=nums[i+1],t=nums[i+2];
                // cout<<f<<s<<t<<" "<<i<<endl;
               if(f==0 && s==0 && t==0){
                         op++;
                         nums[i]=1;
                         nums[i+1]=1;
                         nums[i+2]=1;
                         i+=3;
                 }else if(f==0 && s==0){
                         op++;
                         nums[i+1]=1;
                         nums[i]=1;
                         nums[i+2]=abs(1-nums[i+2]);
                         i+=2;
                 }else if(f==0){
                         op++;
                          nums[i]=1;
                          nums[i+1]=abs(1-nums[i+1]);
                       nums[i+2]=abs(1-nums[i+2]);
                         i++;
                 }else if(f==1){
                    i++;
                 }
         }
            if(nums[n-1]==0 && nums[n-2]==0 && nums[n-3]==0){
                    // cout<<"a"<<endl;
                    return op+1;
            }
            if(nums[n-1]==0 || nums[n-2]==0 ||nums[n-3]==0){
                    return -1;
            }
            return op;
    }
};