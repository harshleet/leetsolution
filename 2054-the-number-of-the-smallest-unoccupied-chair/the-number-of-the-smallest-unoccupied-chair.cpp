class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        set<vector<int>>st;
        for(int i=0;i<times.size();i++){
            st.insert({times[i][0],0,i});
            st.insert({times[i][1],-1,i});
        }

        map<int,int>mp;
        set<int>temp;
        int val=0;
        for(auto it:st){
            if(it[1]==-1){
                temp.insert(mp[it[2]]);
            }else{
                if(temp.empty()){
                    mp[it[2]]=val;
                    val++;
                }else{
                     mp[it[2]]=*(temp.begin());
                     temp.erase(mp[it[2]]);
                }
            }
            
        }
        return mp[targetFriend];
    }
};