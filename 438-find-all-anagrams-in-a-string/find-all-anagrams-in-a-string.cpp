class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        vector<int>fre(26,0);
        for(int i=0;i<s1.size();i++){
            fre[s1[i]-'a']++;
        }
        if(s2.size()<s1.size()){
            return {};
        }
        vector<int>ans;
        vector<int>temp(26,0);
        for(int i=0;i<s1.size();i++){
            temp[s2[i]-'a']++;
        } 
        if(temp==fre){
            ans.push_back(0);
        }
        for(int i=s1.size();i<s2.size();i++){
            temp[s2[i-s1.size()]-'a']--;
            temp[s2[i]-'a']++;
            if(temp==fre){
                ans.push_back(i-s1.size()+1);
            }
        }   
        return ans;    
    }
};