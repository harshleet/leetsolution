class Solution {
public:
    int minChanges(string s) {
        int cnt=1,ans=0;
        char pre=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==pre){
                cnt++;
            }else{
                if(cnt%2==0){
                    cnt=1;
                }else{
                    ans++;
                    cnt=2;
                }
                
            }
            pre=s[i];
        }
        if(cnt%2!=0){
                    
                    ans++;
        }
        return ans;
    }
};