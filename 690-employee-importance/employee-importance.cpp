/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int dfs(int id,map<int,vector<int>>&adj,map<int,int>&impo){
        int ans=impo[id];
        for(auto it:adj[id]){
            ans+=dfs(it,adj,impo);
        }
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        //try to form graph
        map<int,vector<int>>adj;
        map<int,int>impo;
        for(int i=0;i<employees.size();i++){
            for(int j=0;j<employees[i]->subordinates.size();j++){
                adj[employees[i]->id].push_back(employees[i]->subordinates[j]);
            }
            impo[employees[i]->id]=employees[i]->importance;
        }
        //apply dfs two times
        return dfs(id,adj,impo);
    }
};