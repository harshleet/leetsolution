class Solution {
public:
    int maximumSwap(int num) {
        vector<int>v;
        while(num!=0){
            v.push_back(num%10);
            num/=10;
        }
        reverse(v.begin(),v.end());
        cout<<v.size()<<endl;
        bool f=false;
        for(int i=0;i<v.size();i++){
            // cout<<v[i]<<" ";
            int maxi=-1,maxii=-1;
            for(int j=i+1;j<v.size();j++){
                if(v[i]<v[j] && maxi<=v[j]){
                    maxi=max(maxi,v[j]);
                    maxii=j;
                }
            }
            if(maxi!=-1){
                swap(v[i],v[maxii]);
                break;
            }
        }
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans=ans*10+v[i];
        }
       return ans;
    }
};