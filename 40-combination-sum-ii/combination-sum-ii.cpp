class Solution {
public:
set<vector<int>>ans;
void rec(int ind,vector<int>&ds,vector<int>&arr,int n,int target){
     if(target==0){
            ans.insert(ds); 
            return;
       }
       for(int i=ind;i<arr.size();i++){
           if(i>ind && arr[i]==arr[i-1]){
             continue;
         }
           if(target>=arr[i]){ 
                ds.push_back(arr[i]);
                rec(i+1,ds,arr,n,target-arr[i]);
                ds.pop_back();
            }
        }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        rec(0,ds,candidates,candidates.size(),target);
        vector<vector<int>>an(ans.begin(),ans.end());
        return an;
    }
};