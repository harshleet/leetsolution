class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            for(int k=i+1;k<arr.size();k++){
                int a=0,b=0,txor=0;
                for(int j=i;j<=k;j++){
                   txor^=arr[j];
                }
                for(int j=i+1;j<=k;j++){
                    
                    a^=arr[j];
                    txor^=arr[j];
                    b=txor;
                    if(a==b){
                      
                        ans++;
                    }
                }
            }
            
        }
        return ans;
    }
};