class Solution {
public:
    vector<int> minOperations(string boxes) {
         vector<int>ans(boxes.length(),0);
         pair<int,int>p={0,0};
         pair<int,int>s={0,0};
         vector<pair<int,int>>pre(boxes.length());
         vector<pair<int,int>>suf(boxes.length());
         int n=boxes.size();
        for(int i=0;i<boxes.length();i++){
            if(boxes[i]=='1'){
               p.first+=i;
               p.second++;
            }
            if(boxes[n-1-i]=='1'){
                s.first+=(n-1-i);
               s.second++;
            }
           
            pre[i]=p;
            suf[n-1-i]=s;

        }
       
         for(int i=0;i<boxes.length();i++){
           
               ans[i]+=abs(pre[i].second*i-pre[i].first);
               ans[i]+=abs(suf[i].second*i-suf[i].first);
            
        }
        return ans;
    }
};