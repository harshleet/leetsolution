class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int total=-1;
        double twait=0.0;
        for(int i=0;i<customers.size();i++){
            if(total==-1){
                total=customers[i][0]+customers[i][1];
            }else if(total>=customers[i][0]){
                total+=customers[i][1];
            }else if(total<=customers[i][0]){
                total=customers[i][0]+customers[i][1];
            }
            cout<<total<<" ";
            twait+=total-customers[i][0];
        }
        return twait/(double)customers.size();
    }
};