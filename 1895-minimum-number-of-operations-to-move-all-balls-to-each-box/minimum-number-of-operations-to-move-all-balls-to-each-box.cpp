class Solution {
public:
    vector<int> minOperations(string boxes) {
         vector<int>ans;
        for(int j=0;j<boxes.length();j++){
            
                int m=0;
           for(int i=0;i<boxes.length();i++)
           {
              if(boxes[i]=='1')
              {
                    m+=abs(j-i);
              }
           }
           ans.push_back(m);
        }
        return ans;
    }
};