class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>mb(height.size());
        vector<int>mf(height.size());
        mb[0]=0;
        mf.back()=0;
        int mba=height[0],mfr=height.back();
        for(int i=1;i<height.size();i++){
            mb[i]=mba;
            mba=max(mba,height[i]);
        }
        for(int i=height.size()-2;i>=0;i--){
            mf[i]=mfr;
            mfr=max(mfr,height[i]);
        }
        int c=0;
        for(int i=0;i<height.size();i++){
            if(mb[i]==0 || mf[i]==0){
                continue;
            }else if(min(mb[i],mf[i])<=height[i]){
                continue;
            }else{
                c+=min(mb[i],mf[i])-height[i];
            }
        }
        return c;
    }
};