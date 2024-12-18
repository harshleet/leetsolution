class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
  //monotonic decreasing stack

    stack<int>st;
    vector<int>ans;
    int l=prices.size()-1;
    st.push(prices[l]);
    ans.push_back(0);
    
    for(int i=l-1;i>=0;i--){
        while(st.empty()==false && st.top()>prices[i])
            st.pop();
        int ng=st.empty()?0:st.top();
        ans.push_back(ng);
        st.push(prices[i]);
    }
  
        reverse(ans.begin(),ans.end());
         for(int i=0;i<ans.size();i++){
            
                  ans[i]=prices[i]-ans[i];
         }
        return ans;
    }
};