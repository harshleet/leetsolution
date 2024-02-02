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

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
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
    int removeStones(vector<vector<int>>& stones) {
        //mapping of cordinagtes take place
        int mrow=0,mcol=0;
        for(int i=0;i<stones.size();i++){
            mrow=max(mrow,stones[i][0]);
            mcol=max(mcol,stones[i][1]);
        }
        map<int,int>m;
        DisjointSet ds(mrow+mcol+1);
        for(int i=0;i<stones.size();i++){
           int nrow=stones[i][0];
            int ncol=mrow+1+stones[i][1];
            ds.unionBySize(nrow,ncol);
            m[nrow]=1;
            m[ncol]=1;
        }
        set<int>s;
        for(auto it:m){
           s.insert(ds.findUPar(it.first));
        }
        return stones.size()-s.size();
   }
};