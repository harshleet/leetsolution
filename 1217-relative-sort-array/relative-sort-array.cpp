class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       map<int,int>m;
       for(int i=0;i<arr1.size();i++){
        m[arr1[i]]++;
       }
       vector<int>ans;
       for(int i=0;i<arr2.size();i++){
        if(m.find(arr2[i])!=m.end()){
              for(int j=0;j<m[arr2[i]];j++){
                ans.push_back(arr2[i]);
              }
              m[arr2[i]]=0;
        }
       }
       for(auto it:m){
       for(int j=0;j<it.second;j++){
                ans.push_back(it.first);
              }
       }
        return ans;
    }
};