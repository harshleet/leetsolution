class DisjointSet{
    vector<int>par,rank;
    public:
   DisjointSet(int n){
        par.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }
    int findUPar(int node){
        if(node==par[node]){
            return node;
        }
        return par[node]=findUPar(par[node]);
    }

    void unionByRank(int u,int v){
        int upu=findUPar(u);
        int upv=findUPar(v);
        if(upu==upv){
            return;
        }
        if(rank[upu]>rank[upv]){
            par[upv]=upu;
        }else if(rank[upv]>rank[upu]){
            par[upu]=upv;
        }else if(rank[upv]==rank[upu]){
            par[upv]=upu;
            rank[upv]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxr=0,maxc=0;
        for(int i=0;i<stones.size();i++){
              maxr=max(maxr,stones[i][0]);
              maxc=max(maxc,stones[i][1]);
        }
        DisjointSet ds(maxr+maxc+1);
        map<int,int>m;
        for(auto it:stones){
            if(ds.findUPar(it[0])!=ds.findUPar(it[1]+maxr+1)){
                ds.unionByRank(ds.findUPar(it[0]),ds.findUPar(it[1]+maxr+1));
                
            }
            m[it[0]]=1;
            m[it[1]+maxr+1]=1;
        }
        int c=0;
        for(auto it:m){
            if(ds.findUPar(it.first)==it.first){
                c++;
            }
        }
        return stones.size()-c;
    }
};