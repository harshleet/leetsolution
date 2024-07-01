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
    vector<vector<string>> accountsMerge(vector<vector<string>> &details) {
        map<int,set<string>>mp;
        int n=details.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                mp[i].insert(details[i][j]);
            }
        }
        DisjointSet ds(n);
        map<string,int>st;
        for(int i=0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                if(st.find(details[i][j])==st.end()){
                    st[details[i][j]]=i;
                }else{
                    // cout<<i<<" "<<details[i][j]<<endl;
                     int prev=st[details[i][j]];
                    //  cout<<ds.findUPar(prev)<<" "<<endl;
                    //   mp[ds.findUPar(prev)].insert(mp[ds.findUPar(i)].begin(),mp[ds.findUPar(i)].end());
                    //    mp[ds.findUPar(i)].insert(mp[ds.findUPar(prev)].begin(),mp[ds.findUPar(prev)].end());
                      ds.unionBySize(ds.findUPar(prev),ds.findUPar(i)); 
                }
               
            }
        }
        vector<vector<string>>ans;
         for(int i=0;i<n;i++){
            if(ds.findUPar(i)!=i){
                   mp[ds.findUPar(ds.findUPar(i))].insert(mp[i].begin(),mp[i].end());
            }
            
        }
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i){
                vector<string>temp;
                temp.push_back(details[i][0]);
                vector<string>a(mp[i].begin(),mp[i].end());
                temp.insert(temp.end(),a.begin(),a.end());
                ans.push_back(temp);
            }
            
        }
        return ans;
    }
};