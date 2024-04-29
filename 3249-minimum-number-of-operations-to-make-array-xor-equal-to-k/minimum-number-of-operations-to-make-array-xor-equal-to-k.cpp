class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>m(31,0);
        for(int i=0;i<nums.size();i++){
            string b=bitset<31>(nums[i]).to_string();
            for(int j=0;j<31;j++){
                if(b[j]=='1'){
                    m[j]++;
                }
            }
        }
        int n=nums.size();
        int c=0;
        string b=bitset<31>(k).to_string();
       
        if(n==1){
            
            for(int i=0;i<31;i++){
            
                if(b[i]=='1' && m[i]==0){
                    c++;
                }else if(b[i]=='0' && m[i]!=0){
                    c++;
                }
            }
            return c;
        }
        for(int i=0;i<31;i++){
       
            if(b[i]=='0'  && (m[i])%2!=0){
                cout<<" a";
                c++;
            } if(b[i]=='1' && (m[i])%2==0 ){
                cout<<" b";
                c++;
            }
        }
        return c;
    }
};