class Solution {
public:
    int maximumGain(string s, int x, int y) {
       
        if(x>=y){
             stack<pair<char,int>>st;
       
        vector<int>used(s.size(),0);
            int ans=0;
            for(int i=0;i<s.size();i++){
                if(s[i]!='a' && s[i]!='b'){
                    while(!st.empty()){
                        st.pop();
                    }
                  continue;
                }else{
                    if(s[i]=='a'){
                        st.push({s[i],i});
                    }else if(s[i]=='b' && !st.empty() && st.top().first=='a'){
                        ans+=x;
                        used[st.top().second]=1;
                        used[i]=1;
                        st.pop();
                    }
                }
            }
             string temp="";
             for(int i=0;i<s.size();i++){
                if(used[i]==0){
                    temp+=s[i];
                }
             }

             for(int i=0;i<temp.size();i++){
                if(temp[i]!='a' && temp[i]!='b'){
                    while(!st.empty()){
                        st.pop();
                    }
                }else{
                    if(temp[i]=='b'){
                        st.push({temp[i],i});
                    }else if(temp[i]=='a' && !st.empty() && st.top().first=='b'){
                        ans+=y;
                        st.pop();
                    }
                }
            }
            return ans;
            
        }
          stack<pair<char,int>>st;
       
        vector<int>used(s.size(),0);
        int ans=0;
            for(int i=0;i<s.size();i++){
                if(s[i]!='a' && s[i]!='b'){
                    while(!st.empty()){
                        st.pop();
                    }
                }else{
                    if(s[i]=='b'){
                        st.push({s[i],i});
                    }else if(s[i]=='a' && !st.empty() && st.top().first=='b'){
                        ans+=y;
                        used[st.top().second]=1;
                        used[i]=1;
                        st.pop();
                    }
                }
            }
             string temp="";
             for(int i=0;i<s.size();i++){
                if(used[i]==0){
                    temp+=s[i];
                }
             }
          
             for(int i=0;i<temp.size();i++){
                if(temp[i]!='a' && temp[i]!='b'){
                    while(!st.empty()){
                        st.pop();
                    }
                }else{
                    if(temp[i]=='a'){
                        st.push({temp[i],i});
                    }else if(temp[i]=='b' && !st.empty() && st.top().first=='a'){
                        ans+=x;
                        st.pop();
                    }
                }
            }
            return ans;
    }
};