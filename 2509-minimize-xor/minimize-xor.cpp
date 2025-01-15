class Solution {
public:
    int minimizeXor(int num1, int num2) {
        string temp1=bitset<32>(num1).to_string();
        string temp2=bitset<32>(num2).to_string();
        string ans=temp1;
        int cnt=0;
        for(int i=0;i<32;i++){
            if(temp2[i]=='1'){
                cnt++;
            }
        }
       
        for(int i=0;i<32;i++){
            if(cnt>0 && temp1[i]=='1'){
                ans[i]='1';
                cnt--;
            }else{
                ans[i]='0';
            }
        }
        for(int i=31;i>=0;i--){
            if(cnt>0 && temp1[i]=='0'){
                ans[i]='1';
                cnt--;
            }
        }
        //  cout<<temp1<<" "<<temp2<<" "<<ans<<endl;
        int a=stoi(ans, nullptr, 2);
        return a;
    }
};