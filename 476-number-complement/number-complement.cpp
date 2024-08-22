class Solution {
public:
    int findComplement(int num) {
        vector<int>temp;

        while(num!=0){
            temp.push_back((num)%2);
            num/=2;
        }

        // reverse(temp.begin(),temp.end());

        int val=0;
        for(int i=0;i<temp.size();i++){
            // cout<<temp[i];
            val+=((temp[i]+1)%2)*pow(2,i);
        }
        return val;
    }
};