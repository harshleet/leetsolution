class Solution {
public: 
bool check(vector<int>&fre,vector<int>&temp){
    for(int i=0;i<66;i++){
        if(fre[i]>temp[i]){
            return false;
        }
    }
    return true;
}
    string minWindow(string s, string t) {
        vector<int>fre(66,0);
        for(int i=0;i<t.size();i++){
            fre[t[i]-'A']++;
        }
        int j=0;
        vector<int>temp(66);

        int mini=INT_MAX;
        int sti=-1,stj=-1;
        for(int i=0;i<s.size();i++){
            temp[s[i]-'A']++;
            while(check(fre,temp) && j<=i){
                if(mini>i-j+1){
                    mini=i-j+1;
                    sti=i;
                    stj=j;
                }
                temp[s[j]-'A']--;
                j++;
            }
        }
        if(sti==-1 || stj==-1){
            return "";
        }
        return s.substr(stj,sti-stj+1);
    }
};