class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        char pre='0';
       int maxi=0,cnt=0,sum=0,csum=0;
        for(int i=0;i<colors.size();i++){
             if(pre==colors[i]){
                cnt++;
                csum+=neededTime[i];
                maxi=max(maxi,neededTime[i]);
            }else{
                if(cnt>=2){
                    sum+=csum-maxi;
                }
                cnt=1;
                csum=neededTime[i];
                maxi=neededTime[i];
            }
            pre=colors[i];
        }
        if(cnt>=2){
            sum+=csum-maxi;
        }
        return sum;
    }
};