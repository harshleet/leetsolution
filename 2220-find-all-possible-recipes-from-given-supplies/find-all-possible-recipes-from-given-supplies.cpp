class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,int>in;
        map<string,vector<string>>adj;
        for(int i=0;i<recipes.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                adj[ingredients[i][j]].push_back(recipes[i]);
                in[recipes[i]]++;
            }
        }

        queue<string>q;

        for(auto it:supplies){
            q.push(it);
        }
        while(!q.empty()){
            string node=q.front();
            q.pop();

            for(auto it:adj[node]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                }
            }
        }
        vector<string>ans;
        for(int i=0;i<recipes.size();i++){
            if(in[recipes[i]]==0){
                ans.push_back(recipes[i]);
            }
        }
        return ans;

    }
};