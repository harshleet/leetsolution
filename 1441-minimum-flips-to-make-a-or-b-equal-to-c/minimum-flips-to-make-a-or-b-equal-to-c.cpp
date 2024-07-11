class Solution {
public:
  

    int minFlips(int a, int b, int c) {
        string a1=bitset<31>(a).to_string();
        string b1=bitset<31>(b).to_string();
        string c1=bitset<31>(c).to_string();
        vector<int>v(31,0);
        for(int i=0;i<31;i++){
            if(a1[i]=='1'){
                v[i]++;
            }
            if(b1[i]=='1'){
                v[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<31;i++){
            if(c1[i]=='1' && v[i]==0){
                ans++;
            }else if(c1[i]=='0' && v[i]>0){
                ans+=v[i];
            }
        }
        return ans;
    }
};
