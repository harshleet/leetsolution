class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum=0;
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
        }
        long long int rem=k%sum;
        int i=0;
        // cout<<rem<<" ";
        if(rem==0){
            return 0;
        }
        while(rem>0){
            if(rem>=chalk[i]){
                rem-=chalk[i];
            }else{
                return i;
            }
            i++;
        }
        return chalk.size()-1;
    }
};