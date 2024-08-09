class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
       

        set<vector<vector<int>>>st;
        st.insert({{2,7,6},{9,5,1},{4,3,8}});
        st.insert({{2,9,4},{7,5,3},{6,1,8}});
        st.insert({{4,3,8},{9,5,1},{2,7,6}});
        st.insert({{4,9,2},{3,5,7},{8,1,6}});
        st.insert({{6,1,8},{7,5,3},{2,9,4}});
        st.insert({{6,7,2},{1,5,9},{8,3,4}});
        st.insert({{8,1,6},{3,5,7},{4,9,2}});
        st.insert({{8,3,4},{1,5,9},{6,7,2}});

         int n=grid.size(),m=grid[0].size();
        int cnt=0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){  
                vector<vector<int>>temp(3,vector<int>(3));
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        temp[k][l]=grid[i+k][j+l];
                        
                    }
                }
                if(st.find(temp)!=st.end()){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};