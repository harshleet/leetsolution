class Solution {
public:
   
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>dist(26,vector<long long>(26,1e18));
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }

        for(int i=0;i<original.size();i++){
            long long val=(cost[i]);
            dist[original[i]-'a'][changed[i]-'a']=min( dist[original[i]-'a'][changed[i]-'a'],val);
        }

        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                   
                        dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                    
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                if(dist[source[i]-'a'][target[i]-'a']!=1e18){
                    ans=ans+dist[source[i]-'a'][target[i]-'a'];
                }else{
                    return -1;
                }
            }
        }
        
        return ans;
    }
};