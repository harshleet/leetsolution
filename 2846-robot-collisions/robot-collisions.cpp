class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            if(directions[i]=='L'){
                vector<int>temp={positions[i],healths[i],-1,i};
                 v.push_back(temp);
            }else{
                  vector<int>temp={positions[i],healths[i],1,i};
                 v.push_back(temp);
            }
        }
        stack<int>st;
        sort(v.begin(),v.end());

        for(int i=0;i<n;i++){
           
            if(st.empty() || (v[st.top()][2]!=1 || v[i][2]!=-1) ){
                st.push(i);
            }else {
                int lop=-1;
                while(!st.empty() && (v[st.top()][2]==1 && v[i][2]==-1)  ){
                    int vl=st.top();
                    st.pop();
                    if(v[vl][1]==v[i][1]){
                        lop=0;
                        break;
                    }else if(v[vl][1]>v[i][1]){
                        lop=1;
                        v[vl][1]--;
                        st.push(vl);
                        break;
                    }else{
                         v[i][1]--;
                    }
                }
                if(lop==0|| lop==1){
                    continue;
                }else{
                    st.push(i);
                }
            }
        }
        vector<vector<int>>ans;
        while(!st.empty()){
            ans.push_back({v[st.top()][3],v[st.top()][1]});
            st.pop();
        }
        sort(ans.begin(),ans.end());
        vector<int>fin;
        for(int i=0;i<ans.size();i++){
            fin.push_back(ans[i][1]);
        }
        return fin;
    }
};