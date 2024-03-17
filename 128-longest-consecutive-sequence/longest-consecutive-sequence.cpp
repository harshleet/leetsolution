class DisjointSet{
    vector<int>parent,size;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }

        int findUPar(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=findUPar(parent[node]);
        }
        void unionBySize(int u,int v){
            int uPar=findUPar(u);
            int vPar=findUPar(v);
            if(size[uPar]<=size[vPar]){
                parent[uPar]=vPar;
                size[vPar]+=size[uPar];
            }else{
                 parent[vPar]=uPar;
                size[uPar]+=size[vPar];
            }
        }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int maxi=*max_element(nums.begin(),nums.end());
          set<int>st(nums.begin(),nums.end());
        DisjointSet ds(nums.size());
        vector<int>num(st.begin(),st.end());
        for(int i=1;i<num.size();i++){
            if(num[i]-num[i-1]==1){
                ds.unionBySize(i,i-1);
            }
           
            
        }
        int maxs=0;
        map<int,int>m;
        for(int i=0;i<num.size();i++){
          m[ds.findUPar(i)]++;
          maxs=max(maxs,m[ds.findUPar(i)]);
        }
        return maxs;
    }
};