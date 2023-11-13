class Solution {
public:

    int helper(string s,map<char,int>&m,string& tiles,int len,set<string>&st){
         if(len>=tiles.size()){
             if(s.size()!=0)
                st.insert(s);
                return 1;
         }
         int np=helper(s,m,tiles,len+1,st);
         int p=0;
         for(int i=0;i<tiles.size();i++){
             if(m[tiles[i]]!=0){
                 m[tiles[i]]--;
                 p+=helper(s+tiles[i],m,tiles,len+1,st);
                 m[tiles[i]]++;
             }
         }
         return np+p;
    }
    int numTilePossibilities(string tiles) {
        //proper backtracking question
        map<char,int>m;
        for(int i=0;i<tiles.size();i++){
            m[tiles[i]]++;
        }
        set<string>st;
        helper("",m,tiles,0,st);
        return st.size();

    }
};