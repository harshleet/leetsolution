class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        long long int dis=abs(fx-sx);
         long long int dis2=   abs(fy-sy);
     
        long long int ro=max(dis,dis2);
      
        if(ro>t){
            return false;
        }else if(ro==0 && t==1){
            return false;
        }return true;
    }
};