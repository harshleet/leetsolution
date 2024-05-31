class Solution {
public:
//full explnation https://www.youtube.com/watch?v=UA5JnV1J2sI
    vector<int> singleNumber(vector<int>& nums) {
        int val=0,n=nums.size();
        for(int i=0;i<n;i++){
            val^=nums[i];
        }
        // cout<<val<<endl;
        int rb=0;
        while((val &(1<<rb))==0){
            rb++;
        }

        int b1=0,b2=0;
        for(int i=0;i<n;i++){
            
             if((nums[i]&(1<<rb))==0){
                   b1^=nums[i];
             }else{
                cout<<nums[i]<<endl;
                b2^=nums[i];
             }
        }
        return {b1,b2};

    }
}; 