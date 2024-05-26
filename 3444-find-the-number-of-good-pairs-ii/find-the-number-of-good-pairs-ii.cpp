class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans=0;
        map<int,int>m;
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]]++;
        }
        vector<int>ac;
        for(auto it:m){
            if(it.first%k==0){
                ac.push_back(it.first);
            }
        }
         map<int,int>m2;
         for(int i=0;i<nums2.size();i++){
            m2[nums2[i]]++;
        }
        for(int j=0;j<ac.size();j++){
            long long val=ac[j]/k;
        
            for(int i=1;i<=sqrt(val);i++){
               
                if(val%i==0){
                     
                    long long a=m2[i];
                    a*=m[ac[j]];
                    ans+=a;
                    if(i!=val/i){
                    long long a=m2[val/i];
                    a*=m[ac[j]];
                    ans+=a;
                }
                } 
                
            }
        }
        return ans;
    }
};