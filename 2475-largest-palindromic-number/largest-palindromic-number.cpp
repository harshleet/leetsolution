class Solution {
public:
    string largestPalindromic(string num) {
        vector<int>fre(10);
        
        for(int i=0;i<num.size();i++){
                fre[int(num[i]-'0')]++;
        }

        priority_queue<pair<int,int>>pq;
        for(int i=0;i<10;i++){
            
            if(fre[i]>1){
                pq.push({i,(fre[i]/2)*2});
                // cout<<i<<" "<<(fre[i]/2)*2<<endl;
                fre[i]-=(fre[i]/2)*2;
            }
        }

        string ans="";
        while(!pq.empty()){
            int freq=pq.top().second;
            char val=char(pq.top().first+'0');
            pq.pop();
            // cout<<freq<<" "<<val<<endl;
       
            string temp1=ans.substr(ans.size()/2);
             string temp2=temp1;
            reverse(temp1.begin(),temp1.end());
            string s=temp1;
            string toadd(freq,val);
            s+=toadd;
            // cout<<s<<endl;
            s+=temp2;
            ans=s;
           
        }

        for(int i=9;i>=0;i--){
            if(fre[i]>0){
                string temp1=ans.substr(ans.size()/2);
                string temp2=temp1;
                reverse(temp1.begin(),temp1.end());
                string s=temp1;
                s+=char(i+'0');
                s+=temp2;
                ans=s;
                break;
            }
        }
        if(ans=="0" || ans=="00"){
            return "0";
        }
         if(ans.size()>2 && ans[0]=='0' && ans.back()=='0'){
            if(ans.size()%2==1){
                char mid=ans[(ans.size()/2)];
                string a="";
                a+=mid;
                return a;
            }else{
                return "0";
            }
         }
        
        return ans;
    }
};