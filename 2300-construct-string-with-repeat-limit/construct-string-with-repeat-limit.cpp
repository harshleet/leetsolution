class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>>pq;
        vector<int>mp(26,0);
        for(int i=0;i<s.size();i++){
            mp[int(s[i]-'a')]++;
        }
        for(int i=0;i<26;i++){
            if(mp[i]!=0){
                pq.push({char(i+'a'),mp[i]});
                cout<<char(i+'a')<<" "<<mp[i]<<endl;
            }
        }

        string ans="";
        while(!pq.empty()){
            char ch=pq.top().first;
            int fre=pq.top().second;
            pq.pop();
            if(pq.size()==0){
                for(int i=0;i<min(fre,repeatLimit);i++){
                    ans+=ch;
                }
                return ans;
            }
            int a=1;
            for(int i=0;i<fre;i++){
                if(a%(repeatLimit+1)==0 && pq.size()>=1){
                    char temp=pq.top().first;
                    int tempf=pq.top().second;
                    pq.pop();
                    ans+=temp;
                    if(tempf>1){
                        pq.push({temp,tempf-1});
                    }
                    
                    a=1;
                }else if(a%(repeatLimit+1)==0 && pq.empty()){
                    return ans;
                }
                     
                     ans+=ch;
                     a++;
                   
            }
        }
        return ans;
    }
};