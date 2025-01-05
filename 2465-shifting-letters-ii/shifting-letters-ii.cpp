class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>change(s.size()+1,0);
        for(int i=0;i<shifts.size();i++){
                if(shifts[i][2]==1){
                    change[shifts[i][0]]++;
                    change[shifts[i][1]+1]--;
                }
        }
        int sum=0;
        for(int i=0;i<change.size();i++){
               sum+=change[i];
               change[i]=sum; 
        }

        vector<int>change2(s.size()+1,0);
        for(int i=0;i<shifts.size();i++){
                if(shifts[i][2]==0){
                    change2[shifts[i][0]]--;
                    change2[shifts[i][1]+1]++;
                }
        }
        sum=0;
        for(int i=0;i<change2.size();i++){
               sum+=change2[i];
               change2[i]=sum; 
        }
       
        for(int i=0;i<s.size();i++){  
             int shift = change[i] + change2[i];       
            shift = (shift % 26 + 26) % 26;           
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }
        return s;
    }
};