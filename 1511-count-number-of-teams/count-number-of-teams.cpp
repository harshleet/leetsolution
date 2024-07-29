class Solution {
public:
  
    int numTeams(vector<int>& rating) {
        int n=rating.size();

        vector<vector<int>>t(n,vector<int>(4));
        set<int>temp;
        for(int i=0;i<n;i++){
           int leg = distance(temp.begin(), temp.lower_bound(rating[i]));
            int les = temp.size()-leg;
            temp.insert(rating[i]);
            t[i][0] = leg;
            t[i][1] = les;
        }

        set<int>temp2;
        for(int i=n-1;i>=0;i--){
           int rig = distance(temp2.begin(), temp2.lower_bound(rating[i]));
            int ris =temp2.size()-rig;
            temp2.insert(rating[i]);
            t[i][2] = rig;
            t[i][3] = ris;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            // cout<<t[i][0]<<" "<<t[i][1]<<" "<<t[i][2]<<" "<<t[i][3]<<endl;
           ans+=t[i][0]*t[i][3];
           ans+=t[i][1]*t[i][2];
        }
        return ans;

    }
};