class Solution {
public:
  bool is_Pal(long long int val){
    string temp=to_string(val);


    for(int i=0;i<temp.size()/2;i++){
            if(temp[i]!=temp[temp.size()-1-i]){
               return false;
            }
        }
        return true;
  }
    string nearestPalindromic(string n) {
        long long prev=stoll(n);
        int sz=n.size();
        bool f=false;
        if(f==false  ){
           for(int i=1;i<=10;i++){
             if(prev-i>=0 && is_Pal(prev-i)){
                return to_string(prev-i);
             }

             if(is_Pal(prev+i)){
                return to_string(prev+i);
             }
           }
        }
        vector<string>poss;
        vector<long long>pref;

        long long pre=stoll(n.substr(0,(sz+1)/2));
        // cout<<pre<<" ";
        pref.push_back(pre-1);
        pref.push_back(pre);
        
        pref.push_back(pre+1);

        long long mini=LLONG_MAX;
        string minis="";
        for(int i=0;i<pref.size();i++){
            string temp=to_string(pref[i]);
            if(sz%2==1){
                string t=temp.substr(0,temp.size()-1);
                reverse(t.begin(),t.end());
                temp+=t;
             
                long long val=stoll(temp);
                if(mini>abs(val-prev) && abs(val-prev) !=0){
                    mini=abs(val-prev);
                    minis=temp;
                }
            }else{
                string t=temp;
                reverse(t.begin(),t.end());
                temp+=t;
                
                long long val=stoll(temp);
                if(mini>abs(val-prev) && abs(val-prev) !=0){
                    mini=abs(val-prev);
                    minis=temp;
                }
            }
        }
        return minis;
    }
};