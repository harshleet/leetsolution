class Solution {
public:
    int helper(int n,string t,map<char,int>&m){
        if(t.size()>=n){
            return 1;
        }
        int cnt=0;
        for(char i='0';i<='9';i++){
            if(m.find(i)==m.end() ){
                if(t.size()==0 && i=='0'){
                    continue;
                }
                m[i]++;
                t.push_back(i);
                cnt+=helper(n,t,m);
                t.pop_back();
                m.erase(i);
            }
        }
        return cnt;

    }
    int countNumbersWithUniqueDigits(int n) {
        map<char,int>m;
        int cnt=0;
        
         for(int size=1;size<=n;size++){    
                cnt+=helper(size,"",m);
        }
        return cnt+1;
    }
};