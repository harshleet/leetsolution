class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int,multiset<int>>m;
        int r=mat.size(),c=mat[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                 m[i-j].insert(mat[i][j]);
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                 mat[i][j] = *m[i - j].begin(); 
                m[i - j].erase(m[i - j].begin());
            }
        }
        return mat;
    }
};