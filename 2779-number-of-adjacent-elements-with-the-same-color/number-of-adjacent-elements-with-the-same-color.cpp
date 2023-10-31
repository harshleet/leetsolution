class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> v(n, 0);
        vector<int> ans(queries.size());
  int a = 0;
        for (int i = 0; i < queries.size(); i++) {
            int ind = queries[i][0];
            int col= queries[i][1];

            if (ind > 0 && v[ind-1]==col && v[ind-1]!=0)a++;
            if (ind < n-1 && v[ind+1]==col && v[ind+1]!=0)a++;
            

           
           if (ind > 0 && v[ind-1]==v[ind] && v[ind-1]!=0)a--;
           if (ind <n-1 && v[ind+1]==v[ind] && v[ind+1]!=0)a--;

            v[ind]=col;
            ans[i] = a;
        }

        return ans;
    }
};
