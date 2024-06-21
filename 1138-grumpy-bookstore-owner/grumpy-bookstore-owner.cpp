class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int c=0,maxi=0,to=0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0){
                to+=customers[i];
            }
        }
        cout<<to<<" ";
        for(int i=0;i<minutes;i++){
            c+=customers[i];
            if(grumpy[i]==0){
                to-=customers[i];
            }
        }
        maxi=max(maxi,c+to);
        for(int i=minutes;i<customers.size();i++){
             c-=customers[i-minutes];
             if(grumpy[i-minutes]==0){
                to+=customers[i-minutes];
            }
            if(grumpy[i]==0){
                to-=customers[i];
            }
            c+=customers[i];
            maxi=max(maxi,c+to);
        }
        return maxi;
    }
};