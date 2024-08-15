class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>fre(26,0);
        for(int i=0;i<s1.size();i++){
            fre[s1[i]-'a']++;
        }
        if(s2.size()<s1.size()){
            return false;
        }
        vector<int>temp(26,0);
        for(int i=0;i<s1.size();i++){
            temp[s2[i]-'a']++;
        } 
        if(temp==fre){
            return true;
        }
        for(int i=s1.size();i<s2.size();i++){
            temp[s2[i-s1.size()]-'a']--;
            temp[s2[i]-'a']++;
            if(temp==fre){
                return true;
            }
        }   
        return false;    
    }
};