class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
         vector<int>t=skills;
         sort(skills.begin(),skills.end());
         t.insert(t.end(),skills.begin(),skills.end());
         int pre=0,cnt=0;
         k=min(k,int(skills.size()-1));
         for(int i=1;i<t.size();i++){
            if(t[i]>t[pre]){
                pre=i;
                cnt=1;
            }else{
                cnt++;
            }
            if(cnt==k){
                return pre;
            }
         }
         return -1;
    }
};