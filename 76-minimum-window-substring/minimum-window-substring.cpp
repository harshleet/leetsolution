class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mp;
        map<char,int>fre;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
            fre[t[i]]++;
        }

        int j=0;
        int c=fre.size();
        int mini=INT_MAX,minii=-1,minij=-1;
        for(int i=0;i<s.size();i++){
            if(fre.find(s[i])!=fre.end()){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                    c--;
                }
            }

            while(c==0){
                // cout<<i<<" "<<j<<endl;
                if(i-j+1<mini){
                    mini=i-j+1;
                    minii=i;
                    minij=j;
                }
                if(fre.find(s[j])!=fre.end()){
                    mp[s[j]]++;
                    if(mp[s[j]]==1){
                        c++;
                    }
                }
                j++;

            }
            
        }
        if(mini==INT_MAX){
            return "";
        }
        cout<<minij<<" "<<minii<<endl;
        return s.substr(minij,minii-minij+1); 
    }
};