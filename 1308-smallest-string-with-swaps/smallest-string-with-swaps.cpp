class Solution {
public:

class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
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
};
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DisjointSet ds(s.size());

        for(int i=0;i<pairs.size();i++){
            if(ds.findUPar(pairs[i][0])!=ds.findUPar(pairs[i][1])){
               ds.unionByRank(ds.findUPar(pairs[i][0]),ds.findUPar(pairs[i][1]));
            }
        }
        map<int,priority_queue<char,vector<char>,greater<char>>>m;
        for(int i=0;i<s.size();i++){

            m[ds.findUPar(i)].push(s[i]);
        }
        
        string ans="";
        for(int i=0;i<s.size();i++){
            
                ans+=m[ds.findUPar(i)].top();
                m[ds.findUPar(i)].pop();
            
        }
        return ans;
    }
};