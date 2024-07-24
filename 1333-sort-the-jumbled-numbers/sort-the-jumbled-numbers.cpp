class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        for(int i=0;i<nums.size();i++){
            string s="";
            int vl=nums[i];
            if(vl==0){
                s+=to_string(mapping[0]);
            }
            while(vl>0){
                s+=to_string(mapping[vl%10]);
                vl/=10;
            }
            reverse(s.begin(),s.end());
            // cout<<s<<" ";
             int mv=0;
            if(s!=""){
                mv=stoi(s);
            }
           
            pq.push({mv,i,nums[i]});
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(get<2>(pq.top()));
            pq.pop();
        }
        return ans;
    }
};