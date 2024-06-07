class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string>st;
        for(int i=0;i<dictionary.size();i++){
            st.insert(dictionary[i]);
        }
        stringstream ss(sentence);
        string temp;
        string ans="";
        while(getline(ss, temp, ' ')){
            if(ans!=""){
            ans+=" ";}
            bool fl=false;
            for(int i=1;i<=temp.size();i++){
                string sub=temp.substr(0,i);
                if(st.find(sub)!=st.end()){
                    ans+=sub;
                    fl=true;
                    break;
                }
            }
            if(fl==false){
                ans+=temp;
            }
        }
        return ans;
    }
};