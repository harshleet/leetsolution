class ThroneInheritance {
public:
    map<string,vector<string>>adj;
    string king;
    set<string>dead;

    void helper(string node,map<string,int>&vis,vector<string>&ds){
        vis[node]=1;
        if(dead.find(node)==dead.end()){
            ds.push_back(node);
        }

        for(auto it:adj[node]){
            if(vis.find(it)==vis.end()){
                helper(it,vis,ds);
            }
        };
    }
    ThroneInheritance(string kingName) {
        king=kingName;
    }
    
    void birth(string parentName, string childName) {
        adj[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string>ds;
        map<string,int>vis;
        helper(king,vis,ds);
        return ds;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */