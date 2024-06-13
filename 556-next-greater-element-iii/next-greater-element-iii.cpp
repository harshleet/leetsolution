class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>temp;
        while(n>0){
             temp.push_back(n%10);
             n/=10;
        }
        reverse(temp.begin(),temp.end());
        vector<int>ng(temp.size(),-1);
        stack<int>st;
        for(int i=0;i<temp.size();i++){
            if(st.empty() || temp[st.top()]>temp[i]){
                st.push(i);
            }else{
                while(!st.empty() && temp[st.top()]<temp[i]){
                    ng[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
        }
        long long int ans=0,fl=false,ind=-1;
        for(int i=temp.size()-1;i>=0;i--){
            // cout<<temp[i]<<" "<<ng[i]<<endl;
            if(ng[i]!=-1 && fl==false){
                ind=i;
                fl=true;
            }
        }
        if(fl==false){
            return -1;
        }
        int mini=temp[ng[ind]],minii=ng[ind];
        // cout<<temp[ind]<<" "<<mini<<" "<<minii<<endl;
        for(int i=ind+1;i<temp.size();i++){
           if(mini>temp[i] && temp[ind]<temp[i]){
            mini=temp[i];
            minii=i;
           }
        }
        
        swap(temp[ind],temp[minii]);
        sort(temp.begin()+ind+1,temp.end());
        for(int i=0;i<temp.size();i++){
               
                ans=ans*10+temp[i];
               
        }
        cout<<ans<<" "<<INT_MAX<<endl;
          if(ans>INT_MAX){
                    return -1;
         }
        return ans;
    }
};