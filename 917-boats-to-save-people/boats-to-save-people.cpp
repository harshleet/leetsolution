class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int lim=0;
        int n=people.size();
        int npe=0,c=0,i=0,j=n-1;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++;
                j--;
            }else{
               
                j--;
            }
             c++;
        }
        
        return c;
    }
};