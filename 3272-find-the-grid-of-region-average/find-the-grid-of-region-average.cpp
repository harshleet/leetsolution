class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<vector<int>>> avg(n, vector<vector<int>>(m));
        vector<vector<int>> ans = image;

        for (int i = 0; i <= n - 3; ++i) {
            for (int j = 0; j <= m - 3; ++j) {
                int f = false;
                int maxi = 0; 
                int c = 0;
                for (int x = i; x < i + 3; ++x) {
                    for (int y = j; y < j + 3; ++y) {
                        if (y != j) {
                            if(abs(image[x][y] - image[x][y - 1])>threshold){
                                f=true;
                            }
                            
                        }
                        if (x != i) {
                         if(abs(image[x][y] - image[x - 1][y])>threshold){
                             f=true;
                         }
                          
                        }
                        c += image[x][y];
                    }
                }

                if (f==true) {
                    continue;
                }

                for (int x = i; x < i + 3; ++x) {
                    for (int y = j; y < j + 3; ++y) {
                        avg[x][y].push_back(c / 9);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sm = 0;
                for (int k = 0; k < avg[i][j].size(); k++) {
                    sm += avg[i][j][k];
                }
                if(avg[i][j].size()!=0){
                      ans[i][j] = sm / int(avg[i][j].size());
                }
              
            }
        }

        return ans;
    }
};