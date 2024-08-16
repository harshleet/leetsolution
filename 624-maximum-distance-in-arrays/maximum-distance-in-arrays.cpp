class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mx1=INT_MIN,mx2=INT_MIN;
        int mxi=-1;
        int mn1=INT_MAX,mn2=INT_MAX;
        int mni=-1;
        int n=arrays.size();
        for(int i=0;i<n;i++){
            if(mx1<=arrays[i].back()){
                mx2=mx1;
                mx1=arrays[i].back();
                mxi=i;
            }else if(mx2<=arrays[i].back()){
                mx2=arrays[i].back();
            }

            if(mn1>=arrays[i][0]){
                mn2=mn1;
                mn1=arrays[i][0];
                mni=i;
            }else if(mn2>=arrays[i][0]){
                mn2=arrays[i][0];
            }
        }
        if(mxi!=mni){
            return abs(mx1-mn1);
        }
        // cout<<mx1<<" "<<mn2<<" "<<mn1<<" "<<mx2<<endl;
        return max(abs(mx1-mn2),abs(mn1-mx2));
    }
};