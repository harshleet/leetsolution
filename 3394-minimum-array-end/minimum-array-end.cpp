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
        //first intution is hard but you try the testcases on a copy it wis easy

        //keep in mind that 1 in this remain intact what changes is the position whre their is zero's
        // yt -> https://www.youtube.com/watch?v=eA1xIDUqIDc
        string mask=bitset<63>(x).to_string();
        string mask2=bitset<63>(n-1).to_string();
        int j=mask2.size()-1;
        for(int i=mask.size()-1;i>=0;i--){
           if(mask[i]=='0'){
               mask[i]=mask2[j];
               j--;
           }
        }
        long long ans=bitSetToInt(mask);
        return ans;
    }
};