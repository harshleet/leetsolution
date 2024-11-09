class Solution {
public:

    long long bitSetToInt(string &mask){
        long long ans=0;
        for(int i=mask.size()-1;i>=1;i--){
            if(mask[i]=='1'){
               ans+=pow(2,mask.size()-1-i);
            }
        }
        return ans;
    }
    long long minEnd(int n, int x) {
        string t1=bitset<64>(n-1).to_string();
        string t2=bitset<64>(x).to_string();

        // cout<<t1<<" "<<t2<<endl;
        int c=63;
        for(int j=63;j>=0;j--){
            if(t2[j]=='0'){
                t2[j]=t1[c];
                c--;
            }
        }

         long long ans=bitSetToInt(t2);
        return ans;
        
    }
};