class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

   

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& num) {
       
        set<int>s(num.begin(),num.end());
       vector<int>nums(s.begin(),s.end());
       DisjointSet ds(nums.size());
       int n=nums.size();
       for(int i=1;i<n;i++){
          if(nums[i]-nums[i-1]==1){
              ds.unionBySize(i,i-1);
          }
       } 
       unordered_map<int,int>m;
       int maxi=0;
       for(int i=0;i<n;i++){
         int par=ds.findUPar(i);
         m[par]++;
         maxi=max(maxi,m[par]);
       }
       return maxi;
    }
};