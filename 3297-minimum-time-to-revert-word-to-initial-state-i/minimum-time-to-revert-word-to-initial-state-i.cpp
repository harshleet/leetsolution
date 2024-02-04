class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
       int n = word.length();
        int c=1;
        string a="";
        for(int i=k;i<n;i+=k){
            string sub=word.substr(i);
            a="";
            a+=sub;
            for(int j=0;j<n-k;j++){
                a+='*';
            }
            cout<<a<<" ";
            int f=0;
            for(int j=0;j<a.size();j++){
                if(a[j]=='*' || a[j]==word[j]){
                    continue;
                }else{
                    f=1;
                    break;
                }
            }
            if(f==1){
                c++;
            }else{
                break;
            }
        }
        return c;
    }
};