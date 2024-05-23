class Solution {
public:
    int candy(vector<int>& ratings) {
        int ini=1,mini=INT_MAX;
        vector<int>pre(ratings.size(),1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                pre[i]=pre[i-1]+1;
            }
        }

        for(int i=0;i<ratings.size();i++){
            cout<<pre[i]<<" ";
        }
         int sum=pre.back();
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && pre[i]<=pre[i+1]){
                pre[i]=pre[i+1]+1;
               sum+=pre[i];
            }else{
                  sum+=pre[i];
            }
            cout<<sum<<" ";
        }
        return sum;
    }
};