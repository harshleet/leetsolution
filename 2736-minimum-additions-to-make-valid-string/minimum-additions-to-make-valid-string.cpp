class Solution {
public:
    int addMinimum(string word) {
        int i=0;
        int ans=0;
        while(i<word.size()){
            string three=word.substr(i,3);
            string two=word.substr(i,2);
            string one=word.substr(i,1);
            cout<<three;
            if(three=="abc"){
                i+=3;
            }else if(two=="ab" || two=="bc"||two=="ac"){
               ans++;
                i+=2;
            }else{
                ans+=2;
                i++;
            }
        }
        return ans;
    }
};